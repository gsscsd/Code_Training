/**
给定一个二进制数组， 计算其中最大连续1的个数。
示例 1:
输入: [1,1,0,1,1,1]
输出: 3
解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
注意：
输入的数组只包含 0 和1。
输入数组的长度是正整数，且不超过 10,000。
*/

/**
解题思路：
1.动态规划
*/

#include <vector>
#include <string>

using namespace std;

// 时间复杂度:O(n),空间复杂度:O(n)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        vector<int> vec(nums.size(),0);
        vec[0] = nums[0];
        for(int i = 1 ;i < nums.size();i++)
        {
            vec[i] = vec[i - 1] + nums[i]; 
            if(nums[i] == 0) vec[i] = 0;
        }
        return *max_element(vec.begin(),vec.end());
    }
};

// 优化的动态规划,空间复杂度:O(1)
class Solution_ {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int cnt=0,res=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] != 1) cnt=0;
            else cnt++;
            res = cnt > res ? cnt : res;
        }
        return res;
    }
};