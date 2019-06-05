/**
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
注意:
假设字符串的长度不会超过 1010。
示例 1:
输入:
"abccccdd"
输出:
7
解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
*/

/**
解题思路：
计算数字成对出现的字母数量。如果存在一个以上的奇数次出现的字母，则结果加一。

字母ASCII码A~Za~z区间为（65～122）为此，可以使用128的数组标记每个字母出现的次数。
字母出现一次则对应位置记为1，出现两次记为0（同时length统计该字母出现了2次）。
如果所有成对出现的字母数量，小于字符串总长度，则必存在一个以上的奇数次出现的字母。
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


class Solution 
{
    public:
        int longestPalindrome(string s) 
        {
            char twice[128] = {0};
            int length = 0;
            for (auto c : s)
            {
                twice[c] = !twice[c];
                if (!twice[c]){
                    length += 2;
                }
            }
            return length < s.size() ? length +1 : length;
        }
};

int main(int argc, char const *argv[])
{
    return 0;
}
