/**
给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指由字母组成，但不包含任何空格的字符串。

示例:

输入: "Hello World"
输出: 5
*/

/**
解题思路：
从后向前找，遇见空格符并且不是第一个空格符就返回，否则增加字符的数目
*/


#include <iostream>
#include <string>
#include <string>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int re = 0;
        int len = s.length();
        int flag = 0;
        for(int i = len - 1;i >= 0;--i)
        {
            if(s[i] == ' ' && flag == 0) continue;
            flag = 1;
            if(s[i] == ' ') return re;
            else re++;
        }
        return re; 
    }
};


int main()
{
    Solution s;
    string ss = "a ";
    int t = s.lengthOfLastWord(ss);
    cout << t << endl;
    return 0;
}