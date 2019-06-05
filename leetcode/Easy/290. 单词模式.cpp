/**
给定一种 pattern(模式) 和一个字符串 str ，判断 str 是否遵循相同的模式。

这里的遵循指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应模式。

示例1:
输入: pattern = "abba", str = "dog cat cat dog"
输出: true

示例 2:
输入:pattern = "abba", str = "dog cat cat fish"
输出: false

示例 3:
输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false

示例 4:
输入: pattern = "abba", str = "dog dog dog dog"
输出: false
说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。   
*/

/**
解题思路：
字符映射的问题
很眼熟的一个题目，在前面的时候遇见过
考虑是否映射
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>

using namespace std;

class Solution 
{
    public:
        // 解决的方法,使用两个map来映射
        // 时间复杂度为O(n)，空间复杂度为O(n)
        bool wordPattern(string pattern, string str) 
        {
            vector<string> vec;
            // 第一步先用sstream来切分单词
            stringstream ss(str);
            string s;
            while(ss >> s)
            {
                vec.push_back(s);
            }
            int p_l = pattern.length();
            int s_l = vec.size();
            if(p_l != s_l) return false;
            map<char,int> mp;
            map<string,int> ms;
            for(int i = 0; i < p_l;i++)
            {
                mp[pattern[i]] = -1;
                ms[vec[i]] = -1;
            }
            for(int i =0;i < p_l;i++)
            {
                if(mp[pattern[i]] != ms[vec[i]]) return false;
                else mp[pattern[i]] = ms[vec[i]] = i;
            }
            return true;

        }
};

// 解题思路都是一样的
class Solution_ {
public:
    bool wordPattern(string pattern, string str) {
        // 突然想到了一个问题，map的默认值是多少呢？
        map<char, int> p2i;
        map<string, int> w2i;
        istringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (i == n || p2i[pattern[i]] != w2i[word])
                return false;
            p2i[pattern[i]] = w2i[word] = i + 1;
        }
        return i == n;
    }
};

int main()
{

}