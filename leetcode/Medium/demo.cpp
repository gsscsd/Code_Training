/**
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"
*/

/**
解题思路：
1.暴力循环
2.动态规划
动态规划的方法有两种，
    1.按照最长公共字串来做
        设定一个二维数组dp[i][j],找到最长公共字串，未成功
    2.原始动态规划 
        设定一个二维数组dp[i][j],每次从头去计算，按照核心转移方程来做
3.中心扩展，优化之后就是马拉车算法
4.Manacher算法
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
    public : 
        // 第一种方法，暴力循环,时间复杂度为O(n^3)
        string longestPalindrome_0(string s)
        {
            if(s.size() <= 1) return s;
            int max_len = 1;//记录回文串的最大长度
            int start = 0;//记录回文串的起点
            for(int i = 0; i < s.size();i++)
            {
                for(int j = i + 1;j < s.size();j++)
                {
                    int temp1,temp2;
                    // 前后判断字符是否相等
                    for(temp1 = i,temp2 = j; temp1 < temp2;temp1++,temp2--)
                    {
                        // 此处判断跳出循环
                        if(s[temp1] != s[temp2])
                        {
                            break;
                        }
                    }
                    // 此处判断找到了一个回文串，并且回文串的长度大于最大的长度
                    // 注意下面的那个 >= ，因为考虑到奇偶性
                    if(temp1 >= temp2 && j - i + 1 > max_len)
                    {
                        max_len = j - i + 1;
                        start = i;
                    }
                }
            }
            // 循环结束之后，返回回文串
            return s.substr(start,max_len);
        }
        // 第二种方法，采用动态规划来做，这个需要好好研究一下
        // 动态规划是如何分析的，如何找到转移状态方程
        // 尝试采用最长公共字串来解决题目,代码不可以，或者说可以，但是未能解决
        // 一下就当作是最长公共子串的解决模板吧
        string longestPalindrome_1(string s)
        {
            if(s.size() <= 1) return s;
            int s_len = s.size();
            // 将字符串倒转
            string t;
            t.assign(s.rbegin(),s.rend());
            cout << s << endl;
            cout << t << endl;
            // 预定义一个二维的数组
            vector<vector<int> > dp(s_len,vector<int>(s_len,0));
            // 定义回文串的起点
            int start = 0;
            // 定义回文串的长度
            //对边界的计算
            for(int i = 0;i < s_len;i++)
            {
                dp[0][i] = s[0] == t[i] ? 1:0;
            }
            int max_len = 0;
            for(int i = 1;i < s_len;i++)
            {
                // 边界的判断
                dp[i][0] = s[i] == t[0] ? 1 : 0;
                for(int j = 1;j < s_len;j++)
                {
                    // dp[i][j] = s[i] == s[j] ? dp[i - 1][j - 1] + 1:0;
                    if(s[i] == t[j])
                    {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                        start = i - dp[i][j] + 1;
                        max_len = max(max_len,dp[i][j]);
                    }
                }
            }
            if(max_len == 0) max_len += 1;
            return s.substr(start,max_len);
        }
        // 第二种方法，采用动态规划来做，这个需要好好研究一下
        // 动态规划是如何分析的，如何找到转移状态方程
        // 设置二维数组，dp[i][j]分别记录回文串的长度
        string longestPalindrome_2(string s)
        {
            if(s.size() <= 1) return s;
            int s_len = s.size();
            // 预定义一个二维向量dp
            vector<vector<int> > dp(s_len,vector<int>(s_len,0));
            // 定义回文串的起点和最大长度
            int start = 0,max_len = 0;
            // 初始化dp,同时计算长度为1和2的回文串
            for(int i = 0; i < s_len;i++)
            {
                dp[i][i] = 1;
                if(i < s_len - 1)
                {
                    if(s[i] == s[i + 1])
                    {
                        dp[i][i+1] = 1;
                        start = i;
                        max_len = 2;
                    } 
                }
            }
            // 对回文串长度开始循环计算
            // 先计算回文串为3的字符串
            for(int l = 3;l <= s_len;l++)
            {
                // 定义每个字符串的开始
                for(int i = 0;i + l - 1 < s_len ;i++)
                {
                    // 定义回文串的尾部
                    int j = l + i - 1;
                    if(s[i] == s[j] && dp[i + 1][j - 1] == 1)
                    {
                        dp[i][j] = 1;
                        start = i;
                        // 回文串的长度
                        max_len = l;
                    }
                }
            }
            return s.substr(start,max_len);
        }
        // 另一种比较容易理解的动态规划的方法
        // 这种方法容易理解，但是不如上面的那种方法高效
        string longestPalindrome_3(string s)
        {
            if(s.size() <= 1) return s;
            int s_len = s.size();
            // 预定义一个二维向量dp
            vector<vector<bool> > dp(s_len,vector<bool>(s_len,false));
            // 定义回文串的起点和最大长度
            int start = 0,max_len = 0;
            // 两层for循环,i是字符的起点,j是递推的计算字符的终点
            for(int i = 0;i < s_len;i++)
            {
                for(int j = 0;j <= i;j++)
                {
                    // 如果是相邻的字符
                    if(i - j < 2)
                    {
                        // 判断这两个字符是否相等
                        dp[j][i] = (s[i] == s[j]);
                    }
                    else 
                    {
                        dp[j][i] = (s[i] == s[j] && dp[j + 1][i - 1]);
                    }
                    // 如果当前是回文串，并且还有最大长度
                    if(dp[j][i] && max_len < i - j + 1)
                    {
                        max_len = i - j + 1;
                        start = j;
                    }
                }
            }
            return s.substr(start,max_len);
        }
        // 中心扩展的方法，暂时还不会
        // Manacher算法
        string longestPalindrome_4(string s)
        {
            if(s.size() <= 1) return s;
            // 定义一个vector<char>
            vector<char> vec;
            vec.push_back('#');
            // 插入特殊字符
            for(int i = 1;i < s.size();i++)
            {
                vec.push_back(s[i]);
                vec.push_back('#');
            }
            // for(auto v : vec)
            // {
            //     cout << v;
            // }
            // 定义id和mxright
            int id,mx = -1;
            // 定义最大长度,以及回文串的开始位置
            int max_len = 0,start = 0;
            // 定义辅助数组
            vector<int> p(vec.size(),0);
            // 遍历寻找
            for(int i = 1;i < vec.size();i++)
            {
                if(i < mx)
                    p[i] = min(p[2 * id - 1],mx - i);
                else p[i] = 1;
                while(i - p[i] >= 0 && i - p[i] <= vec.size() && vec[i - p[i]] == vec[i + p[i]])
                p[i]++;
                // 更新id和mx
                if(p[i] + i > mx) 
                {
                    mx = p[i] + i - 1;
                    id = i;
                }
                // 更新最长回文串的长度
                // max_len = max(max_len, p[i]);
                if(max_len < p[i])
                {
                    max_len = p[i];
                    start = i - max_len;
                }
            }
            return "#";
        }
};


int main(int argc, char const *argv[])
{
    string s;
    Solution so;
    cin >> s;
    string t = so.longestPalindrome_4(s);
    cout << t << endl;
    
    return 0;
}




