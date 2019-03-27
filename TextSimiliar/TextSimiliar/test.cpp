#include "TextSimilarity.h"
#include <iostream>
using namespace std;
//void testWordFreq()
//{
//	TextSimilarity ts("dict");
//	TextSimilarity::wordFreq wf = ts.getWordFreq("test.txt");
//	
//	for (const auto& w : wf)
//	{
//		cout << ts.UTF8ToGBK(w.first) << ": " <<w.second << endl;
//	}
//	vector<pair<string, int>>wfvec = ts.sortByValueReverse(wf);
//
//	for (const auto& w : wfvec)
//	{
//		cout << ts.UTF8ToGBK(w.first) << ": " << w.second<< endl;
//	}
//}
//
//void testOneHot()
//{
//	TextSimilarity ts("dict");
//	TextSimilarity::wordFreq wf = ts.getWordFreq("test.txt");
//	TextSimilarity::wordFreq wf2 = ts.getWordFreq("test2.txt");
//	vector<pair<string, int>> wfvec = ts.sortByValueReverse(wf);
//	vector<pair<string, int>>wfvec2 = ts.sortByValueReverse(wf2);
//	cout << "wfvec: " << endl;
//	for (int i = 0; i < 10; i++)
//	{
//		cout << ts.UTF8ToGBK(wfvec[i].first )<< ": " << wfvec[i].second << "\t";
//	}
//	cout << endl;
//	cout << "wfvec2: " << endl;
//	for (int i = 0; i < 10; i++)
//	{
//		cout << ts.UTF8ToGBK(wfvec2[i].first) << ": " << wfvec2[i].second << "\t";
//	}
//	cout << endl;
//	TextSimilarity::wordSet wset;
//	//用排好序的词频挑选前N个候选词
//	ts.selectAimWords(wfvec, wset);
//	ts.selectAimWords(wfvec2, wset);
//	cout << "wset:" << endl;
//	for (const auto& e : wset)
//	{
//		cout << ts.UTF8ToGBK(e) << " " ;
//	}
//	cout << endl;
//	//根据候选词构建词频向量
//	vector<double> oneHot = ts.getOneHot(wset, wf);
//	vector<double> oneHot2 = ts.getOneHot(wset, wf2);
//	cout << "oneHot:" << endl;
//	for (const auto& v : oneHot)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//	cout << "oneHot2:" << endl;
//	for (const auto& v : oneHot2)
//	{
//		cout << v << " ";
//	}
//	cout << "cosine: " << ts.cosine(oneHot, oneHot2) << endl;
//}
//int main()
//{
//	//testWordFreq();
//	testOneHot();
//	getchar();
//	return 0;
//}

//int main(int argc, char** argv)
//{
//	if (argc != 4)
//	{
//		cout << "Usage: " << argv[0] << "<dict-dir> <file1> <file2>";
//		return 1;
//	}
//
//	TextSimilarity ts(argv[1]);

//	cout <<"cosine: "<< ts.getTextSimilarity(argv[1], argv[2]);
//	return 0;
//}

int main()
{
	TextSimilarity test = { "../dict" };

	string  file1 = "./test.txt";
	string  file2 = "./test2.txt";
	cout << test.getTextSimilarity(file1.c_str(), file2.c_str());
	return 0;
}