/**
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，
使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

/**
解题思路：
三重循环
核心思路还是只有2数和能双指针。3数4数不过是外面继续套循环
*/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        set<vector<int>> ans;
        if (nums.size() < 4)
            return vector<vector<int>>(ans.begin(), ans.end());
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int l = 0, r = nums.size() - 1;
                while (l < r)
                {
                    if (l == i)
                    {
                        break;
                    }
                    if (r == j)
                    {
                        break;
                    }
                    if (nums[l] + nums[r] + nums[i] + nums[j] == target)
                    {
                        vector<int> tmp;
                        tmp.push_back(nums[l]);
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[r]);
                        ans.insert(tmp);
                        ++l;
                        --r;
                    }
                    else if (nums[l] + nums[r] + nums[i] + nums[j] < target)
                    {
                        ++l;
                    }
                    else
                        --r;
                }
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

class Solution_0
{
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < int(nums.size() - 3); ++i)
        {
            for (int j = i + 1; j < int(nums.size() - 2); ++j)
            {
                // 跳过相同的数
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int left = j + 1, right = nums.size() - 1;
                while (left < right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                        res.insert(out);
                        ++left;
                        --right;
                    }
                    else if (sum < target)
                        ++left;
                    else
                        --right;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};
