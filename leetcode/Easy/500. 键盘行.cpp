/**
给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。
示例：

输入: ["Hello", "Alaska", "Dad", "Peace"]
输出: ["Alaska", "Dad"]
 

注意：

你可以重复使用键盘上同一字符。
你可以假设输入的字符串将只包含字母。
*/

/**
解题思路：
*/

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution 
{
    public:
        vector<string> findWords(vector<string>& words) 
        {
            vector<string> res;
            
            for(auto word :words)
                res = help(word,res);
            return res;
        }
        // 定义辅助函数，将大写字符转成小写字符
        string up2low(string s)
        {
            string res = "";
            for(auto i :s)
                res += tolower(i);
            return res;
        }
        // 定义辅助函数，寻找一行字符
        vector<string> help(string word,vector<string> &vec)
        {
            string str1 = "qwertyuiop";
            string str2 = "asdfghjkl";
            string str3 = "zxcvbnm";

            string str = up2low(word);

            if(str1.find(str[0]) != -1)
            {
                for(int i = 1;i < str.size();i++)
                    if(str2.find(str[i]) != -1 || str3.find(str[i]) != -1)
                        return vec;
            }
            if(str2.find(str[0]) != -1)
            {
                for(int i = 1;i < str.size();i++)
                    if(str1.find(str[i]) != -1 || str3.find(str[i]) != -1)
                        return vec;
            }
            if(str3.find(str[0]) != -1)
            {
                for(int i = 1;i < str.size();i++)
                    if(str1.find(str[i]) != -1 || str2.find(str[i]) != -1)
                        return vec;
            }
            vec.push_back(word);
            return vec;
        }

};
