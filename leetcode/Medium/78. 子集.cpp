/**
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

/**
解题思路：
1.标准的递归+回溯
2.位运算
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// 非递归的解法
/***
我们可以一位一位的往上叠加，比如对于题目中给的例子[1,2,3]来说，最开始是空集，
那么我们现在要处理1，就在空集上加1，为[1]，现在我们有两个自己[]和[1]，下面我们来处理2，
我们在之前的子集基础上，每个都加个2，可以分别得到[2]，[1, 2]，那么现在所有的子集合为[], [1], [2], [1, 2]，
同理处理3的情况可得[3], [1, 3], [2, 3], [1, 2, 3], 再加上之前的子集就是所有的子集合了。
*/
class Solution_1
{
  public:
    vector<vector<int>> subsets(vector<int> &S)
    {
        vector<vector<int>> res(1);
        sort(S.begin(), S.end());
        for (int i = 0; i < S.size(); ++i)
        {
            int size = res.size();
            for (int j = 0; j < size; ++j)
            {
                res.push_back(res[j]);
                res.back().push_back(S[i]);
            }
        }
        return res;
    }
};

/**
深度优先遍历
dfs函数来遍历
*/
class Solution
{
  public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int index = 0;
        vector<vector<int>> res;
        vector<int> temp;
        if (nums.empty())
            return res;
        dfs(res, nums, 0, temp);
        return res;
    }
    // 深度优先遍历
    void dfs(vector<vector<int>> &res, vector<int> &nums, int index, vector<int> &temp)
    {
        // 如果索引大于nums.size()
        if (index >= nums.size())
        {
            res.push_back(temp);
            return;
        }
        res.push_back(temp);
        for (int i = index; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            dfs(res, nums, i + 1, temp);
            temp.pop_back();
        }
    }
};

/**
位运算的解法
数组 [1,2,3] 的子集也就是其中的三个元素取与不取的组合。把它想象为二进制的三个 bit 位 1 1 1，
那么从 0 0 0 到 1 1 1 的 8 个数，就构成了所有子集的选取情况。比如 0 0 1 表示取第1个元素，0 1 1 表示取前两个元素。
*/
class Solution_0
{
  public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ret;
        ret.push_back({});
        int size = nums.size();
        int subsize = 1 << size;
        int hash = 1;
        while (hash < subsize)
        {
            vector<int> temp;
            for (int k = 0; k < size; k++)
            {
                // 注意以下的代码
                // 1左移k位
                int a = 1 << k;
                if (a & hash)
                {
                    temp.push_back(nums[k]);
                }
            }
            ret.push_back(temp);
            hash++;
        }
        return ret;
    }
};

/**
另一种位运算
*/
class Solution_2
{
  public:
    vector<vector<int>> subsets(vector<int> &S)
    {
        vector<vector<int>> res;
        sort(S.begin(), S.end());
        int max = 1 << S.size();
        for (int k = 0; k < max; ++k)
        {
            cout << "k ---" << k << endl;
            vector<int> out = convertIntToSet(S, k);
            res.push_back(out);
        }
        return res;
    }
    vector<int> convertIntToSet(vector<int> &S, int k)
    {
        vector<int> sub;
        int idx = 0;
        for (int i = k; i > 0; i >>= 1)
        {
            cout << "k " << k << " i " << i << endl;
            if ((i & 1) == 1)
            {
                cout << idx << endl;
                sub.push_back(S[idx]);
            }
            ++idx;
        }
        return sub;
    }
};