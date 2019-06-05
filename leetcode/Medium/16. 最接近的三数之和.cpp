/**
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
找出 nums 中的三个整数，使得它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/

/**
解题思路：
先排序，然后遍历寻找最接近的答案 
*/


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution
{
    public :
        int threeSumClosest(vector<int>& nums, int target) 
        {
            sort(nums.begin(),nums.end());
            int res = nums[0] + nums[1] + nums[2];
            for(int i = 0;i < nums.size();++i)
            {
                int l = i + 1,h = nums.size() - 1;
                while(l < h)
                {
                    int threeSum = nums[i] + nums[l] + nums[h];
                    if(abs(threeSum - target) < abs(res - target))
                    {
                        res = threeSum;
                    }
                    if(threeSum > target) h--;
                    else if(threeSum < target) l++;
                    else return target;
                }  
            }
            return res;
        }
};