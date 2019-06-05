/**
题目描述
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,
并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
 */


/**
解题思路
字符串加入到map里面，然后在去遍历
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        
        map<char,int> dict;
        for(int i = 0;i < str.length();++i)
        {
            dict[str[i]]++;
        }
        // 注意下面这个想法，还是通过str来遍历
        for(int i = 0;i < str.size();++i)
        {
            if(dict[str[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};


int main()
{
    return 0;
}