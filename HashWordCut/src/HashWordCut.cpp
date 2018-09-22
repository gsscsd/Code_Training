#include "../include/HashWordCut.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

#define len 3

WordCut::WordCut()
{
    cout << "read dict." <<endl;
    ifstream in(path);
    string s;
    while(getline(in,s))
    {
        // cout << 
        wordDict.insert(pair<string,string>(s,""));
    }
//    wordDict.insert(pair<string,string>("中国", ""));
//    wordDict.insert(pair<string,string>("北京", ""));
//    wordDict.insert(pair<string,string>("中关村", ""));
//    wordDict.insert(pair<string,string>("海淀区", ""));
}

void WordCut::printAll()
{
    //multimap的遍历只能用迭代器方式不能用数组
    cout << "***************************************" << endl;
    cout << "********print map dict content********" << endl;
    map<string,string>::iterator i,iend;
    iend=wordDict.end();
    for(i=wordDict.begin();i!=iend;i++)
    {
        cout <<(*i).first<<" gg\n";
    }
    cout << "***************************************" << endl;
}

void WordCut::word_cut(std::string text)
{

    //中文3B
    cout << "OK" << endl;
    int length = text.size();
    for (int i = 0;i < length;i += len)
    {
        int endIndex = i + maxLength * len;
        if(endIndex > length)
        {
            endIndex = length;
        }
        for (int j = 0;j < maxLength;j++)
        {
            string s = text.substr(i,endIndex - i);
//            cout << "i is " << i <<  " end is "<<endIndex << endl;
//            cout << "s is " << s << endl;
            if(wordDict.count(s) != 0){
                //跳过匹配过的词（后面会说明跳过匹配词的原因）
                cout << s << endl;
                i = endIndex - len;
                break;
            }
            else
            {
                endIndex -= len ;
                if(endIndex == i){
                    break;
                }
            }

        }

    }

}
WordCut::WordCut(int8_t size)
{

    WordCut();
    maxLength = size;

}