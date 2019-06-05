/**
给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。

示例：
给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()
sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

说明:
你可以假设数组不可变。
会多次调用 sumRange 方法。
*/

/**
解题思路：
根据题目的说明，可以得知，sumRange方法是多次的调用
因此，我们需要考虑sumRange方法的时间复杂度是O(1)
*/
#include <iostream>
#include <vector>

using namespace std;

// 一种方法是定义一个数组来保存输入的数组
class NumArray 
{
    public:
        NumArray(vector<int> nums) 
        {
            num = nums;
        }
        
        int sumRange(int i, int j) 
        {
            int sum = 0;
            for(int k = i;k <= j ;k++) sum += num[k];
            return sum;
        }
    private:
        vector<int> num;
};
// 第二种高效的方法是定义一个数组来保存前序和
// 大神的考虑的边界很不错
class NumArray_ {
public:
    NumArray_(vector<int> nums) {
      sum.resize(nums.size(), 0);
      for (int i = 0; i < nums.size(); i++)
        sum[i] = i ? nums[i] + sum[i - 1] : nums[i];
    }
    
    int sumRange(int i, int j) {
        return sum[j] - (i ? sum[i - 1] : 0);
    }
private:
  vector<int> sum;
};