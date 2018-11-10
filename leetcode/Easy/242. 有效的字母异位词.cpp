/**
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。

示例 1:
输入: s = "anagram", t = "nagaram"
输出: true

示例 2:
输入: s = "rat", t = "car"
输出: false
说明:
你可以假设字符串只包含小写字母。
进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
unicode字符的编码是多少呢？
*/

/**
解题思路：
字母异位词
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

// 大神的代码
class Solution {
public:
    bool isAnagram(string s, string t) {
        // 第一次碰见使用set数据结构的
        return multiset<char>(s.begin(), s.end()) == multiset<char>(t.begin(), t.end());
    }
};

// 通过设定一个字符数组做映射
class Solution_ {
public:
    bool isAnagram(string s, string t) {
        int characters[26] = {0};
        // 通过char字符数组统计出现的次数
        for(int i=0; i<s.size(); i++){
            characters[s[i]-'a'] = characters[s[i]-'a']+1;
        }
        // 然后在t数组减去相应的次数
        for(int i=0; i<t.size(); i++){
            characters[t[i]-'a']--;
        }
        // 如果字符数组中的数组不为0，那么返回false
        for(int i=0; i<26; i++){
            if(characters[i]!=0)
                return false;
        }
        return true;
    }
};
// 解题思路都差不多，都是通过计算字符出现的次数，来计算的
class Solution_ {
public:
    bool isAnagram(string s, string t) {
        int lens = s.size(),lent = t.size();
        if(lens != lent) return false;
        int s1[26] = {0},t1[26] = {0};
        for(int i = 0;i < lens; i++)
        {
            s1[s[i] - 'a'] += 1;
            t1[t[i] - 'a'] += 1;
        }
        for(int i = 0;i < 26; i++)
        {
            if(s1[i] != t1[i]) return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
