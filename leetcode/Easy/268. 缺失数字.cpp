/**
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。

示例 1:
输入: [3,0,1]
输出: 2

示例 2:
输入: [9,6,4,2,3,5,7,0,1]
输出: 8
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
*/

/**
解题思路：
小象学院邹老师的数组讲过
是否考虑双指针呢？
for循环遍历元素，如果，当前下标与当前元素值不相等，那么交换A[i] = A[A[i]]
如果，当前元素大于数组的长度,或者小于下标又或者nums[i] == nums[nums[i]],则，删除元素
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        // 如果不考虑使用额外的常数空间，那么就是说，可以采用原数组来操作
        if (nums.size() <= 0 ) return -1;
        int i = 0,j = nums.size() - 1;
        // 核心代码，遍历操作
        while(i <= j )
        {
            if(nums[i] == i) i++;
            // 如果越界或者是重复出现，那么就删掉
            // 删除的方法是交换到尾部
            else if((nums[i] < i ) || (nums[i] > j) || (nums[i] == nums[nums[i]]))
            {
                nums[i] = nums[j];
                j--;
            }
            else 
            {
                // 否则交换nums[i],nums[nums[i]];
                swap(nums[i],nums[nums[i]]);
            }
        }
        return i ;
    }
};

// 大神的代码，依然那么犀利呀
class Solution_ {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        int sum = 0;
        int n = nums.size();
        for (int num:nums)
            sum += num;
        // 这一行应该是核心代码
        // 方法是均值公式
        x = (n + 1.0)/ 2 * n - sum;
        return x;
    }
};


int main()
{
    return 0;
}

