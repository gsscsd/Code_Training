/**
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2

示例 2:
输入: haystack = "aaaaa", needle = "bba"
输出: -1
*/


/**
解题思路：
1.暴力求解
2.kmp算法 
*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
            if(needle.size() == 0) return 0;
            if(haystack.size() == 0) return -1;
            if(haystack.size() < needle.size()) return -1;
            int i = 0;
            int j = 0;
            for(i;i < haystack.size() - needle.size() + 1;i++)
            {
                //     cout <<  << haystack[i] << endl;
                    bool is_no = true;
                    for(j = 0; j < needle.size();j++)
                    {
                            if(haystack[i + j] != needle[j])
                            {
                                    is_no = false;
                            }
                    }
                    if(is_no)
                    {
                            cout << i << endl;
                            return i;
                    }
            }
            return -1;  
    }
};


int main(int argc, char const *argv[])
{
        string a0 ;
        string a1 ;
        cin >> a0;
        cin >> a1;

        Solution s;
        int t = s.strStr(a0,a1);
        cout << t << endl;

        return 0;
}
