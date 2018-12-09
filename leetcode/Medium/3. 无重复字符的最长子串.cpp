/**
 给定一个字符串，找出不含有重复字符的最长子串的长度。

示例 1:
输入: "abcabcbb"
输出: 3 
解释: 无重复字符的最长子串是 "abc"，其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 无重复字符的最长子串是 "b"，其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 无重复字符的最长子串是 "wke"，其长度为 3。
     请注意，答案必须是一个子串，"pwke" 是一个子序列 而不是子串。
*/

/**
解题思路：
1.暴力for循环
2.优化的方法，使用map来做，不会做，参考大神的答案
就是用map<char,int>这种数据结构
PS:这道题目：除了暴力的方法，其他方法暂时不会
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Solution 
{
    public : 
        // 大神的代码，暂时看不明白
        int lengthOfLongestSubstring(string s) 
        {
                map<char, int> mp;
                for (int i=0; i < s.length(); i++)
                    mp[s[i]] = -1;//初始化哈希表
                int pre = -1, Max = 0;
                for (int i=0; i < s.length(); i++)
                {
                    pre = max(pre, mp[s[i]]);
                    Max = max(Max, i - pre);
                    mp[s[i]] = i;
                }
            return Max;
        }
        // 另一种解法，PS:字符是有限数据
        // 通过构建一个哈希表映射字符
        // 其实不太理解
        int lengthOfLongestSubstring_(string s) {
            vector<int> dict(256,-1);
            int maxLen = 0;int start = -1;
            for(int i = 0;i < s.length();++i)
            {
                if(dict[s[i]] > start)
                    start = dict[s[i]];
                maxLen = max(i-start,maxLen);
                dict[s[i]] = i;
            }
            return maxLen;
    }
};
// leetcode 高效率答案
class Solution_ {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        int start = 0,end = 1;
        int max = 1;
        bool  dic[255];
        memset(dic,0,sizeof(bool) * 255);
        char c = s.at(start);
        dic[c] = true;
        int len = s.size();
        while(start < len && end < len)
        {
            
            if(dic[s.at(end)])
            {
                dic[s.at(start++)] = false;
            }
            else
            {
                dic[s.at(end)] = true;

                //Check if find the max length
                if(end - start + 1> max)
                    max = end - start + 1;

                ++end;
            }
        }
    
        return max;
        
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    string ss = "aabaab!bb";
    int t = s.lengthOfLongestSubstring(ss);
    cout << t << endl;
    return 0;
}




