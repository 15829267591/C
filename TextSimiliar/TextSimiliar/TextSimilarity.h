#pragma once
#include<unordered_map>
#include <string>
#include <cppjieba/Jieba.hpp>
#include <unordered_set>

class TextSimilarity
{
public:
	typedef std::unordered_map<std::string, int>wordFreq;
	typedef std::unordered_set<std::string>wordSet;//用来存放停用词
	TextSimilarity(std::string dict);
	double getTextSimilarity(const char* file, const char* file2);
	
private:

	void getStopWordTable(const char* stopWordFile);
	wordFreq getWordFreq(const char* file);

	std::string UTF8ToGBK(std::string str);
	std::string GBKToUTF8(std::string str);
	std::vector<std::pair<std::string, int>> sortByValueReverse(wordFreq &wf);
	void selectAimWords(std::vector<std::pair<std::string, int>>&wfvec, wordSet& wset);  //把排序后的前多少个词拿出来，放到wset中
	std::vector<double> getOneHot(wordSet& wset, wordFreq &wf);      //构建词频向量

	double cosine(std::vector<double>oneHot1, std::vector<double>oneHot2);
	
	std::string DICT;
	std::string DICT_PATH;
	std::string HMM_PATH;
	std::string USER_DICT_PATH;
	std::string IDF_PATH;
	std::string STOP_WORD_PATH;

	cppjieba::Jieba _jieba;
	wordSet _stopWordSet;

	int _maxWordNumber;
};