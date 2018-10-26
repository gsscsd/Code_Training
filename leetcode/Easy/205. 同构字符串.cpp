/**
给定两个字符串 s 和 t，判断它们是否是同构的。
如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。

示例 1:
输入: s = "egg", t = "add"
输出: true

示例 2:
输入: s = "foo", t = "bar"
输出: false

示例 3:
输入: s = "paper", t = "title"
输出: true
*/

/**
解题思路：
第一时间想到的方法就是做映射
个人的分析是，由于至少遍历一次，所以时间复杂度为(n)，空间复杂度为O(n)
使用两个数组进行双映射
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution 
{
    public:
        bool isIsomorphic(string s, string t) 
        {
            // mp映射s，imp映射t
            vector<int> smp(256,-1),tmp(256,-1); 
            if(s.size() == 0) return true;
            for(int i = 0 ;i < s.size();i++)
            {
                if(smp[s[i]] != tmp[t[i]]) return false;
                else smp[s[i]] = tmp[t[i]] = i;
            }
            return true;
        }
};

int main(int argc, char const *argv[])
{


    return 0;
}