#include "TextSimilarity.h"
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <assert.h>
using namespace std;

TextSimilarity::TextSimilarity(string dict)
	:DICT(dict)
	,DICT_PATH( "C:/Users/hp/source/repos/TextSimiliar/dict/jieba.dict.utf8")
	, HMM_PATH( "C:/Users/hp/source/repos/TextSimiliar/dict/hmm_model.utf8")  
	, USER_DICT_PATH("C:/Users/hp/source/repos/TextSimiliar/dict/user.dict.utf8")
	, IDF_PATH( "C:/Users/hp/source/repos/TextSimiliar/dict/idf.utf8")
	, STOP_WORD_PATH( "../dict/stop_words.utf8")
	, _jieba(DICT_PATH,
		HMM_PATH,
		USER_DICT_PATH,
		IDF_PATH,
		STOP_WORD_PATH)
	, _maxWordNumber(10)
{
		getStopWordTable(STOP_WORD_PATH.c_str());
}
TextSimilarity::wordFreq TextSimilarity::getWordFreq(const char* filename)
{
	ifstream fin(filename);
	if (!fin.is_open())
	{
		cout << "open file: " <<filename << "failed!" << endl;
		return wordFreq(); //û�д򿪣���һ���յĴ�Ƶ
	}
	string line;
	wordFreq wf;
	while (!fin.eof())
	{
		getline(fin, line);
		//GBK-->UTF8
		line = GBKToUTF8(line);
		vector<string> words;
		//���ı���ǰ�зִʣ�����ŵ�vector
		_jieba.Cut(line, words, true);
		//ͳ�ƴ�Ƶ
		for (const auto& e : words)
		{
			//ȥ��ͣ�ô�
			if (_stopWordSet.count(e) > 0) 
				continue;
			else
			{
				//ͳ�ƴ�Ƶ
				if (wf.count(e) > 0)
					wf[e]++;
				else
					wf[e] = 1;
			}
		}
	}
	return wf;
}
void  TextSimilarity::getStopWordTable(const char* stopWordFile)
{
	ifstream fin(stopWordFile);
	if (!fin.is_open())
	{
		cout << "open file" << stopWordFile << "failed!" << endl;
		return;
	}
	string line;
	while (!fin.eof())
	{
		getline(fin, line);
		_stopWordSet.insert(line);
	}
	fin.close();
}

string TextSimilarity::GBKToUTF8(string str)
{
	//��ȡbuffer��С
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len];
	//GCK-->UTF16
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, wstr, len);
	//��UTF16 ת������Ҫ�ĸ�ʽ
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* utf8char = new char[len];
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, utf8char, len, NULL, NULL);
	string out(utf8char);
	if (wstr)
	{
		delete[] wstr;
		wstr = NULL;
	}
	if (utf8char)
	{
		delete[] utf8char;
		utf8char = NULL;
	}
	return out;
}
bool cmpReverse(pair<string, int> lp, pair<string, int>rp)
{
	return lp.second > rp.second;
}
//��������
vector<pair<string, int>> TextSimilarity::sortByValueReverse(TextSimilarity::wordFreq &wf)
{
	//unordered_map
	vector<pair <string, int>> wfvector(wf.begin(), wf.end());      //���ã�
	sort(wfvector.begin(), wfvector.end(),cmpReverse);  //sortֻ֧����������
	return wfvector;
}
string TextSimilarity::UTF8ToGBK(string str)
{
	//��ȡbuffer��С
	int len = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len];
	//UTF8-->UTF16
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wstr, len);
	//��UTF16 ת������Ҫ�ĸ�ʽ
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* gbkchar = new char[len];
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, gbkchar, len, NULL, NULL);
	string out(gbkchar);
	if (wstr)
	{
		delete[] wstr;
		wstr = NULL;
	}
	if (gbkchar)
	{
		delete[] gbkchar;
		gbkchar = NULL;
	}
	return out;
}

void TextSimilarity::selectAimWords(std::vector<std::pair<std::string, int>>&wfvec, wordSet& wset)
{
	int len = wfvec.size();
	int sz = len > _maxWordNumber ? _maxWordNumber : len; //ȡС��
	for (int i = 0; i < sz; i++)
	{
		//pair<string, int>
		wset.insert(wfvec[i].first);
	}
}
vector<double> TextSimilarity::getOneHot(TextSimilarity::wordSet& wset, TextSimilarity::wordFreq &wf)
{
	//����wordSet�е�ÿһ����
	vector<double>oneHot;
	for (const auto& e : wset)  //��set�ı���˳�����
	{
		if (wf.count(e))
			//oneHot(value)
			oneHot.push_back(wf[e]);
		else
			oneHot.push_back(0);
	}
	return oneHot;
}

double TextSimilarity::cosine(std::vector<double>oneHot1, std::vector<double>oneHot2)
{
	double modular1 = 0, modular2 = 0;
	double products = 0;
	assert(oneHot1.size() == oneHot2.size());
	for (int i = 0; i < oneHot1.size(); i++)
	{
		//sum(a(i)*b(i))
		products += oneHot1[i] * oneHot2[i];
	}
	for (int i = 0; i < oneHot1.size(); i++)
	{
		modular1 += pow(oneHot1[i], 2);
	}
	modular1 = pow(modular1, 0.5);
	for (int i = 0; i < oneHot2.size(); i++)
	{
		modular2 += pow(oneHot2[i], 2);
	}
	modular1 = pow(modular2, 0.5);
	return products / (modular2 * modular1);
}

double TextSimilarity::getTextSimilarity(const char* file, const char* file2)
{
	TextSimilarity::wordFreq wf = getWordFreq(file);
	TextSimilarity::wordFreq wf2 = getWordFreq(file2);
	vector<pair<string, int>> wfvec = sortByValueReverse(wf);
	vector<pair<string, int>>wfvec2 = sortByValueReverse(wf2);
	cout << "wfvec: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << UTF8ToGBK(wfvec[i].first) << ": " << wfvec[i].second << "\t";
	}
	cout << endl;
	cout << "wfvec2: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout <<UTF8ToGBK(wfvec2[i].first) << ": " << wfvec2[i].second << "\t";
	}
	cout << endl;
	TextSimilarity::wordSet wset;
	//���ź���Ĵ�Ƶ��ѡǰN����ѡ��
	selectAimWords(wfvec, wset);
	selectAimWords(wfvec2, wset);
	cout << "wset:" << endl;
	for (const auto& e : wset)
	{
		cout << UTF8ToGBK(e) << " ";
	}
	cout << endl;
	//���ݺ�ѡ�ʹ�����Ƶ����
	vector<double> oneHot = getOneHot(wset, wf);
	vector<double> oneHot2 =getOneHot(wset, wf2);
	cout << "oneHot:" << endl;
	for (const auto& v : oneHot)
	{
		cout << v << " ";
	}
	cout << endl;
	cout << "oneHot2:" << endl;
	for (const auto& v : oneHot2)
	{
		cout << v << " ";
	}
	cout << endl;
	//cout << "cosine: " << cosine(oneHot, oneHot2) << endl;
	return cosine(oneHot, oneHot2);
}