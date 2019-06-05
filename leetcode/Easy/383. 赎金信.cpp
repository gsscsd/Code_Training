/**
给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能
由第二个字符串magazines里面的字符构成。如果可以构成，返回 true ；否则返回 false。

(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。)

注意：
你可以假设两个字符串均只含有小写字母。

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

/**
解题思路：
这个是一个映射问题
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        int mag[26] = {0};
        for (int i = 0; i < magazine.size(); ++i)
        {
            ++mag[magazine[i]-'a'];
        }
        for (int i = 0; i < ransomNote.size(); ++i)
        {
            if (--mag[ransomNote[i]-'a'] < 0){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}