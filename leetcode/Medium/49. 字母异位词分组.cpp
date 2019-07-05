/**
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：
所有输入均为小写字母。
不考虑答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> hmAll;
        vector<vector<string>> res;
        for (int i = 0; i < strs.size(); i++)
        {
            string key = strs.at(i);
            sort(key.begin(), key.end());
            hmAll[key].push_back(strs.at(i));
        }
        for (auto iter = hmAll.begin(); iter != hmAll.end(); iter++)
        {
            res.push_back(iter->second);
        }
        return res;
    }
    vector<vector<string>> groupAnagrams1(vector<string> &strs)
    {

        vector<vector<string>> res;
        unordered_map<double, vector<string>> hmAll;
        map<char, int> hmNum = {
            {'a', 2}, {'b', 3}, {'c', 5}, {'d', 7}, {'e', 11}, {'f', 13}, {'g', 17}, {'h', 19}, {'i', 23}, {'j', 29}, {'k', 31}, {'l', 37}, {'m', 41}, {'n', 43}, {'o', 47}, {'p', 53}, {'q', 59}, {'r', 61}, {'s', 67}, {'t', 71}, {'u', 73}, {'v', 79}, {'w', 83}, {'x', 89}, {'y', 97}, {'z', 101}};
        for (int i = 0; i < strs.size(); i++)
        {
            double sum = 1;
            for (int j = 0; j < strs.at(i).size(); j++)
            {
                sum *= hmNum[strs.at(i).at(j)];
            }
            hmAll[sum].push_back(strs.at(i));
        }
        for (auto iter = hmAll.begin(); iter != hmAll.end(); iter++)
        {
            res.push_back(iter->second);
        }
        return res;
    }
};