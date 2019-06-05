/**
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。
例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
/**
解题思路：
1.先排序数组，
2. 遍历数组的每一个元素nums[i]，在i之后的数组中找合为-nums[i]的两个数，
3. 两数之和可以用首尾逼近法求解。 
感觉上O(n^3)
// 考虑到重复的元素，此时可以使用set
*/

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
        // 数组排序
        sort(nums.begin(), nums.end());
        // 头尾指针遍历
        for (int i = 0; i < nums.size() - 2; i++)
        {
            //跳过相同元素
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, h = nums.size() - 1;

            while (l < h)
            {
                if (-nums[i] > nums[l] + nums[h])
                    l++;
                else if (-nums[i] < nums[l] + nums[h])
                    h--;
                else
                {
                    vector<int> temp({nums[i], nums[l], nums[h]});
                    // temp.push_back(nums[i]);
                    // temp.push_back(nums[l]);
                    // temp.push_back(nums[h]);
                    res.push_back(temp);
                    l++;
                    h--;
                    // 跳过相同的元素
                    while (l < h && nums[l] == nums[l - 1])
                    {
                        l++;
                    }
                    while (l < h && nums[h] == nums[h + 1])
                    {
                        h--;
                    }
                }
            }
        }
        return res;
    }
};

// 使用set，防止重复
class Solution_0
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> ans;
        if (nums.size() < 3)
            return vector<vector<int>>(ans.begin(), ans.end());
        // 先排序
        sort(nums.begin(), nums.end());
        int left, right, target;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            // 这里不懂，为什么大于0，要跳过
            if (nums[i] > 0)
            {
                break;
            }
            if (nums[i] == nums[i - 1] && i > 0)
                continue;
            left = i + 1, right = nums.size() - 1, target = -nums[i];
            while (left < right)
            {
                if (nums[left] + nums[right] == target)
                {
                    ans.insert({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                }
                else if (nums[left] + nums[right] > target)
                {
                    --right;
                }
                else
                {
                    ++left;
                }
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};