/**
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
] 
*/

/**
解题思路
1. 递归
2. 非递归，字典序 
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// 递归搜索算法
class Solution
{
  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        int end = nums.size() - 1;
        dfs(nums, res, 0, end);
        return res;
    }
    // 去重的递归算法
    bool isSwap(const vector<int> &nums, int start, int end)
    {
        for (int i = start; i < end; i++)
            if (nums[i] == nums[end])
                return false;
        return true;
    }

    void dfs(vector<int> &nums, vector<vector<int>> &res, int level, int end)
    {
        if (level == end)
        {
            res.push_back(nums);
        }
        else
        {
            for (int i = level; i <= end; i++)
            {
                if (!isSwap(nums, level, i))
                    continue;
                swap(nums[i], nums[level]);
                // 注意这里是每次从进入level的下一层
                dfs(nums, res, level + 1, end);
                swap(nums[i], nums[level]);
            }
        }
    }
};

// 第二种递归回溯算法
// 效率比较低下
class Solution_0
{
  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        // tmp是中间存储变量，visit是标记位
        vector<int> tmp, visit(nums.size(), 0);
        // 回溯算法
        backTracking(nums, 0, tmp, visit, res);
        return res;
    }
    void backTracking(vector<int> &nums, int level, vector<int> tmp, vector<int> &visit,
                      vector<vector<int>> &res)
    {
        if (level == nums.size())
        {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            // 如果当前位已经被使用，则跳过
            if (visit[i] == 1)
                continue;
            visit[i] = 1;
            tmp.push_back(nums[i]);
            backTracking(nums, level + 1, tmp, visit, res);
            tmp.pop_back();
            visit[i] = 0;
        }
    }
};

// 非递归的字典序算法
class Solution_1
{
  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        // 方便练习sort的第三个参数
        // 先从小到大排序
        sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });
        res.push_back(nums);
        // while (next_permutation(nums.begin(), nums.end()))
        // {
        //     res.push_back(nums);
        // }

        // while(nextPermutation(nums))
        // {
        //     res.push_back(vector<int>(nums));
        // }
        return res;
    }
    bool nextPermutation(vector<int> &nums)
    {
        int sw1 = -1, sw2 = -1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1]) //找到第一个前面比后面小的值
            {
                sw1 = i;
                break;
            }
        }
        // 如果没有找到后面大于前面的，那就说明已经没有下一个最大排序了
        if (sw1 == -1)
            return false;
        for (int i = nums.size() - 1; i >= sw1; --i)
        {
            if (nums[i] > nums[sw1])
            {
                sw2 = i;
                break;
            }
        }
        swap(nums[sw1], nums[sw2]);
        sort(nums.begin() + sw1 + 1, nums.end());
        return true;
    }
};
