/**
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


// 递归的解法+去重
class Solution
{
  public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
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

// 非递归的字典序算法
class Solution_1
{
  public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
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

        while(nextPermutation(nums))
        {
            res.push_back(nums);
        }
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

