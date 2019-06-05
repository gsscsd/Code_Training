/**
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
说明:
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
*/

/**
解题思路：
1. 递归+哈希表 C++实现
2. dfs深度搜索加回溯
宽搜适合用迭代实现，深搜适合用递归实现。
*/

#include <vector>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

// 第一种方法，dfs
class Solution
{
  public:
    vector<string> letterCombinations(string digits)
    {
        map<int, string> mp;
        mp[1] = "";
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        vector<string> res;
        string str = "";
        if (digits.length() == 0)
            return res;
        // dfs深度搜索，回溯，递归等等
        dfs(digits, mp, res, str, 0);
        return res;
    }
    // dfs搜索，深度搜索加回溯
    void dfs(string digits, map<int, string> &mp, vector<string> &res, string &str, int index)
    {
        // 递归边界
        if (str.size() == digits.size())
        {
            res.push_back(str);
            return;
        }
        for (int i = index; i < digits.size(); i++)
        {
            for (int j = 0; j < mp[digits[i] - '0'].size(); j++)
            {
                str += mp[digits[i] - '0'][j];
                // 深度优先遍历
                dfs(digits, mp, res, str, i + 1);
                str.pop_back();
            }
        }
    }
};
// 另一种深度搜索
class Solution_1
{
  public:
    void dfs(vector<string> &aa, string digits, int level, vector<string> &re, string s)
    {
        if (level == digits.size())
            re.push_back(s);
        for (char x : aa[digits[level] - '0'])
        {
            dfs(aa, digits, level + 1, re, s + x);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> aa{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.empty())
            return vector<string>{};
        vector<string> re;
        string s;
        dfs(aa, digits, 0, re, s);
        return re;
    }
};
// 暴力循环迭代
class Solution_2
{
  public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> aa{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.empty())
            return vector<string>{};
        vector<string> re{""};
        for (char x : digits)
        {
            vector<string> aaa;
            for (auto y : re)
                for (auto z : aa[x - '0'])
                    aaa.push_back(y + z);
            re = aaa;
        }
        return re;
    }
};
// 第二种方法，bfs
class Solution_0
{
  public:
    vector<string> letterCombinations(string digits)
    {
        // https://blog.csdn.net/Scarlett_Guan/article/details/79916603  宽搜 深搜
        vector<string> aa{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.empty())
            return vector<string>{};
        queue<string> re;
        re.push("");
        for (int i = 0; i < digits.size(); ++i)
        {
            int length = re.size();
            for (int j = 0; j < length; ++j)
            {
                string temp = re.front();
                re.pop();
                for (char x : aa[digits[i] - '0'])
                {
                    re.push(temp + x);
                }
            }
        }
        vector<string> ans;
        while (!re.empty())
        {
            ans.push_back(re.front());
            re.pop();
        }
        return ans;
    }
};