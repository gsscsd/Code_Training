/**
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/
/**
解题思路：
1.暴力遍历,貌似是最简单的动态规划,
2.分治


PS：
新学的一招
用来加速输入和输出的
std::ios::sync_with_stdio(false);
std::cin.tie(0);
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Solution {
public:
    // 如果用数组的话，此时的空间复杂度为O(n)
    int maxSubArray(vector<int>& nums) {
        // 异常边界的处理
        if(nums.size() <= 1) return nums[0];
        // 设定一个数组，用来存储，到当前位置的最大值，
        vector<int> vec(nums.size(),0);
        vec[0] = nums[0];
        for(int i = 1;i < nums.size();++i)
        {
            vec[i] = max(nums[i] + vec[ i - 1],nums[i]);
        }
        int result = INT32_MIN;
        for(auto v : vec)
        {
            if(v > result) result = v;
        }
        return result;
    }
    // 考虑一下，用一个中间变量来缓存，用一个result存储最后的结果
    int maxSubArray_(vector<int> & nums)
    {
        // 设定中间值与最后的结果
        int temp = 0,result = INT32_MIN;
        for(int i = 0;i < nums.size();++i)
        {
            temp += nums[i];
            if(temp > result) result = temp;
            // 其实一直对这里不太理解呢，为什么要对于小于0的进行归零处理
            // 其实就是加上每次的下标的数
            if(temp < 0) temp = 0;
        }
        return result;
    }
};
// 加速对输出输入来处理
static auto _=[]()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();


int main()
{
    vector<int> vec;
    Solution s;
    // -2,1,-3,4,-1,2,1,-5,4
    vec.push_back(-2);
    vec.push_back(1);
    // vec.push_back(-3);
    // vec.push_back(4);
    // vec.push_back(-1);
    // vec.push_back(2);
    // vec.push_back(1);
    // vec.push_back(-5);
    // vec.push_back(4);

    int t = s.maxSubArray_(vec);
    cout << t << endl;

    return 0;
}