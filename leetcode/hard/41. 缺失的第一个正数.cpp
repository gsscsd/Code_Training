/**
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:

输入: [1,2,0]
输出: 3
示例 2:

输入: [3,4,-1,1]
输出: 2
示例 3:

输入: [7,8,9,11,12]
输出: 1
说明:

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
*/

/**
解题思路：
遍历一次数组把大于等于1的和小于数组大小的值放到原数组对应位置，
然后再遍历一次数组查当前下标是否和值对应，如果不对应那这个下标就是答案，
否则遍历完都没出现那么答案就是数组长度加1。 
*/


#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>


using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int res = 1;
        int num_size = nums.size();
        for(int i = 1; i <= num_size;)
        {
            // 注意下面的这个if判断条件，边界判断加位置判断，否则进入无线循环
            if(nums[i - 1] > 0 && nums[i - 1] < num_size && nums[nums[i - 1] - 1] != nums[i - 1])
            {
                swap(nums[nums[i - 1] - 1],nums[i - 1]);
            }
            else i++;
        }
        for(;res <= num_size;res++)
        {
            if(nums[res - 1] != res)
            {
                return res ;
            }
        }
        return res ;
    }
};