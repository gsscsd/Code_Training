/**

编写一个函数，其作用是将输入的字符串反转过来。

示例 1:

输入: "hello"
输出: "olleh"
示例 2:

输入: "A man, a plan, a canal: Panama"
输出: "amanaP :lanac a ,nalp a ,nam A"
*/

/**
解题思路：
好简单的，按照自己的思路来做就行
*/

#include <iostream>
#include <string>

using namespace std;


class Solution 
{
    public:
        string reverseString(string s) 
        {
            char t = ' ';
            int j = s.length();
            for(int i = 0;i < j / 2;i++)
            {
                swap(s[i],s[j - 1 -i]);
            };
            return s;
        }
};

