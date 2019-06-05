/**
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

/**
解题思路：
全排列
定义了两个辅助函数,互换(swap)和序列逆转(reverse). 觉得这种方法很好.有一点双指针的意思
用nums = [1,3,5,7,6,4,2,1]来做示范吧. 首先,第一个指针从队尾开始向前遍历(i = len(nums) - 2),
判断一下i+1与i的大小关系.在遍历到5之前,一直是nums[i]>nums[i+1]. 在第一个指针指向5时,
第二个指针同样从队尾出发,因为在逆向遍历到i之前,一直是升序的,刚开始nums[j] <= nums[i]是一直满足的,
当j停止移动时,j指向的数字是刚刚好大于nums[i]的,在例子中,j刚好指向6.
将nums[i]与nums[j]进行互换.此时nums = [1,3,6,7,5,4,2,1].此时6之后的数字是降序的,
所以将6之后数字进行反转,才能达到题目要求"刚好大于原序列的效果",然后将nums[i+1:]进行反转即可.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 解法一：
// 使用内置的函数
class Solution
{
  public:
    void nextPermutation(vector<int> &nums)
    {
        next_permutation(nums.begin(), nums.end());
    }
};
// 解法二：
// 手动实现,效率有些低
class Solution
{
  public:
    void nextPermutation(vector<int> &nums)
    {
        int sw1 = -1, sw2 = -1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1]) //找到第一个前面比后面小的值
            {
                sw1 = i;
                break;
            }
        }
        if (sw1 == -1)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        for (int i = nums.size() - 1; i >= sw1; --i)
        {
            if (nums[i] > nums[sw1])
            {
                sw2 = i;
                break;
            }
        }
        cout << sw1 << "=====" << sw2 << endl;
        swap(nums[sw1], nums[sw2]);
        sort(nums.begin() + sw1 + 1, nums.end());
        for (auto i : nums)
            cout << i << endl;
    }
};