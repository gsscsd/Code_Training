/**
给定两个字符串 s 和 t，它们只包含小写字母。
字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
请找出在 t 中被添加的字母。
示例:
输入：
s = "abcd"
t = "abcde"
输出：
e
解释：
'e' 是那个被添加的字母。
*/

/***
解题思路：
又是映射问题
*/

#include <iostream>
#include <map>


using namespace std;


class Solution {
    public:
        char findTheDifference(string s, string t) 
        {
            int ch[26] = {0};
            for(auto i : t)
            {
                ch[i - 'a'] ++;
            }
            for(auto i : s)
            {
                ch[i - 'a'] --;
            }
            for(int i = 0;i < 26;i++)
            {
                if(ch[i] == 1) return i + 'a';
            }
        }
};


// 使用与或算法
// 具体内部的算法不太理解
class Solution_ {
public:
    char findTheDifference(string s, string t) {
        char ans = t[0];
        for(int i=0;i<s.length();i++)
        {
            ans ^= s[i];
            ans ^= t[i+1];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
