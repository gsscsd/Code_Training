/**
给定一个字符串 (s) 和一个字符模式 (p)。实现支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符。
'*' 匹配零个或多个前面的元素。
匹配应该覆盖整个字符串 (s) ，而不是部分字符串。

说明:

s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
示例 1:

输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。
示例 2:

输入:
s = "aa"
p = "a*"
输出: true
解释: '*' 代表可匹配零个或多个前面的元素, 即可以匹配 'a' 。因此, 重复 'a' 一次, 字符串可变为 "aa"。
示例 3:

输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个('*')任意字符('.')。
示例 4:

输入:
s = "aab"
p = "c*a*b"
输出: true
解释: 'c' 可以不被重复, 'a' 可以被重复一次。因此可以匹配字符串 "aab"。
示例 5:

输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
*/

/**
解题思路：
1.动态规划
2.递归
*/

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// 递归的解题思路
// 一、当模式中的第二个字符不是“*”时：
// 1、如果字符串第一个字符和模式中的第一个字符相匹配，那么字符串和模式都后移一个字符，然后匹配剩余的。
// 2、如果字符串第一个字符和模式中的第一个字符相不匹配，直接返回false。
// 二、当模式中的第二个字符是“*”时：
// 如果字符串第一个字符跟模式第一个字符不匹配，则模式后移2个字符，继续匹配。
// 如果字符串第一个字符跟模式第一个字符匹配，可以有3种匹配方式：
// 1、x*匹配0个字符。模式后移2字符，相当于x*被忽略；（一开始忘了即使当前字符匹配，也存在忽略掉的情况！！！）
// 2、x*匹配1个字符。字符串后移1字符，模式后移2字符；
// 3、x*匹配多于1个字符。字符串后移1字符，模式不变，即继续匹配字符下一位，因为*可以匹配多位；
// 注意：情况2可以被情况1和情况3包含。执行一次情况3，再执行一次情况1，就相当于情况2。

// 下面的代码中，如果使用string.at会出错，而使用[],不会出错
// 这种解法不太容易理解，而且代码里面还不健壮
class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        // 边界判断：
        if (p.empty())
            return s.empty();
        if (p.size() == 1)
            return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        // 接下来分情况来判断第二个是字符是否是*
        // 如果第二个字符是*
        if (p[1] != '*')
        {
            if (s[0] == p[0] || (!s.empty() && p[0] == '.'))
                return isMatch(s.substr(1), p.substr(1));
            else
                return false;
        }
        // 如果第二个字符是*
        else
        {
            // 下面的代码不太理解了
            if (s[0] == p[0] || (!s.empty() && p[0] == '.'))
                return isMatch(s, p.substr(2)) || isMatch(s.substr(1), p);
            else
                return isMatch(s, p.substr(2));
        }
    }
};

// 递归解法2
// 这种解法容易理解
class Solution_0
{
  public:
    bool isMatch(string s, string p)
    {
        // 边界判断，如果匹配式为空，字符串不为空，则无法正确匹配
        //  当 p 为空串时，只有目标串 s 的空串才能与 p 匹配；
        if (p.empty())
            return s.empty();
        // 如果匹配式不为空，字符串为空，则仅当剩下的匹配式皆为‘a*’模式才可以
        // 当 s 为空串时，只有 p 为 空串 或者 为 x*y* 的形式才能与 s 匹配。
        if (s.empty())
        {
            // 递归的消除"*"
            if (p.size() >= 2 && p.at(1) == '*')
                return isMatch(s, p.substr(2));
            // 否则不匹配，返回false
            else
                return false;
        }
        // 匹配式，字符串都不为空
        // 判断第一个字符是否匹配
        bool firstMatch = (s.at(0) == p.at(0) || p.at(0) == '.');
        if (p.length() >= 2 && p.at(1) == '*')
            //如果为‘a*’模式，则可以选择使用它，或者去除它
            return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));
        else
            //如果不是‘a*’模式，则只能使用当前字符，即判断字符时候相等
            return firstMatch && isMatch(s.substr(1), p.substr(1));
    }
};

// 直接使用正则表达式
class Solution_1
{
  public:
    bool isMatch(string s, string p)
    {
        // 直接使用C++正则表达式
        regex reg1(p);
        return regex_match(s, reg1);
    }
};

// 动态规划
class Solution_2
{
  public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        // 动态规划来做
        bool result[m + 1][n + 1] = {false};
        result[0][0] = true;
        for (int i = 0; i <= m; i++)
            for (int j = 1; j <= n; j++)
            {
                 // 每次s字符串往下走一个字符，和所有的p子串进行匹配，接下来分两种情况进行分类。
                // ( a )  假设当前位置为dp[i][j]，若p[j-1] == "*"时，"*"的用法分为两种（1：代表空串  2：代表一个或者多个前一个字符）
                // 要想dp[i][j] =1，需要满足下列条件中的任一个：
                //  (a.1）dp[i][j-2] =1时，此时"*"代表空串
                //  (a.2）dp[i-1][j] =1时且满足（p[j-2]==s[i-1] or p[j-2]=="."），此时"*"代表对前一字符的复制
                // ( b )  若p[j-1]!= "*"时，要想dp[i][j] =1，需满足（p[j-1]==s[i-1] or p[j-1]=="."），且还要判断前面的是否匹配，即dp[i-1][j-1]的值是否为True。

                if (p.at(j - 1) == '*')
                {
                    //这里i j 可以有三种情况转化而来。 1. s去掉*和*之前字母能够匹配。也就是*之前字母取0次。
                    // 2.*和*之前字母取一次,匹配s中第i个字母，（用递归 所以从1次开始往后几次也是都可以）
                    // 3.这种情况是& 也就是 一定要匹配s中第i-1 。
                    // 也是因为*之前字母可以取0次，换句话说如果不能匹配i-1 那么一定不能匹配[i][j]
                    result[i][j] = result[i][j - 2] || ((i > 0) && (s.at(i - 1) == p.at(j - 2) || p.at(j - 2) == '.')) && result[i - 1][j];
                }
                else
                {
                    // 把. 当成普通字符一起匹配。这个就比较简单当前位置一样，或者是. 并且[i-1][j-1]也是要匹配
                    result[i][j] = i > 0 && (s.at(i - 1) == p.at(j - 1) || p.at(j - 1) == '.') && result[i - 1][j - 1];
                }
            }
        return result[m][n];
    }
};
