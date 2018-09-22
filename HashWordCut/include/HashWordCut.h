#ifndef HashWordCut
#define HashWordCut 

#include <iostream>
#include <map>
#include <cstring>

class WordCut
{
public:
    void word_cut( std::string text);
    WordCut(std::int8_t size);
    WordCut();
    void printAll();

private:
    std::string path = "../dict/dict.txt";
    std::int8_t maxLength = 5;
    std::map<std::string,std::string> wordDict ;
};

#endif