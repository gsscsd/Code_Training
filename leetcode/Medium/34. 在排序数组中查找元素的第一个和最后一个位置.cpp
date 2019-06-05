/**
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。
示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/

/**
解题思路：
二分查找，在查找到元素之后，左右寻找
*/

// #include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        if(nums.empty()) return res;
        int lo = 0,hi = nums.size() - 1;
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) >> 1;
            // 左右扩充搜索
            if(nums[mid] == target)
            {
                int i = mid;
                while(i >= 0 && nums[i] == target) i--;
                int j = mid;
                while(j <= nums.size() && nums[j] == target) j++;
                res[0] = i + 1;
                res[1]  = j - 1;
                break;
            }
            else if(nums[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return res;
    }
};
