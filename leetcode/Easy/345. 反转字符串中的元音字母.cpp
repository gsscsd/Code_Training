/**
编写一个函数，以字符串作为输入，反转该字符串中的元音字母。

示例 1:

输入: "hello"
输出: "holle"
示例 2:

输入: "leetcode"
输出: "leotcede"
说明:
元音字母不包含字母"y"。
*/

/**
解题思路：
双指针，前后一起遍历
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
    public:
        string reverseVowels(string s) 
        {
            int i = 0,j = s.length();
            for(;i < j;)
            {
                if(!isVowels(s[i])) i++;
                if(!isVowels(s[j])) j--;
                if(isVowels(s[i]) && isVowels(s[j]))
                {
                    swap(s[i],s[j]);
                    i++;j--;
                }
            }
            return s;
            
        }
        bool isVowels(char c)
        {
            char ch = tolower(c);
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                return true;
            return false;
        }
};


int main(int argc, char const *argv[])
{
    return 0;
}
