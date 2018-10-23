/**
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]

示例 2:
输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]

说明:
尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的原地算法。
*/

/**
解题思路：
1.非常巧的思路：
做这个题目，刚好碰到小象学院在讲这个题目
三次原地反转即可实现，也可以用于字符串的反转上
2.设定一个O(k)的空间
3.执行O(kn)次原地交换
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution
{
    public:
        void rotate(vector<int>& nums, int k) 
        {
            if(nums.size() <= 1) return ;
            int n = nums.size();
            k = k % nums.size();
            // 注意参数的k是向右移动
            // 反转前面的数组
            swapVec(nums,0,n - k);
            // 反转后面部分的数组
            swapVec(nums,n - k,n);
            // 反转整体的数组
            swapVec(nums,0,n);
        }
        void swapVec(vector<int> &nums,int start,int end)
        {
            for(int i = start;i < (end + start) / 2;i++)
            {
                int temp = nums[i];
                nums[i] = nums[end - i - 1 + start];
                nums[end - i - 1 + start] = temp;
            }
        }
};


int main(int argc, char const *argv[])
{
    /* code */
    vector<int > vec;

    return 0;
}

