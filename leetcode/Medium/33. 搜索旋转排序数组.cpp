/**
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
*/

/**
解题思路：
必须使用折半查找
不要被“旋转”而迷惑，“有序”并不是二分查找的核心
二分查找的核心是"通过界桩快速决定查找方向，大幅缩短查找空间"
只要能快速确定界桩，就能使用二分查找
充分利用有序数组能够快速获取边界值的特性
利用这一特性可以快速确定目标值应处的区间
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {

        if (nums.empty())
            return -1;

        int li = 0, ri = nums.size() - 1;
        while (li <= ri)
        {
            int mid = (li + ri) / 2;
            if (nums[mid] == target)
                return mid;
            // 只要在普通的二分查找判断语句中加一层 && 来确定目标值所在的区间，即可以同样O(logn)的复杂度查找
            if (nums[li] <= nums[mid] && (nums[li] <= target && target < nums[mid]))
                ri = mid - 1;
            else if (nums[mid] <= nums[ri] && !(nums[mid] < target && target <= nums[ri]))
                ri = mid - 1;
            else
                li = mid + 1;
        }
        return -1;
    }
};

class Solution_0
{
  public:
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;
        int left = 0, right = nums.size() - 1, mid; //左闭右闭区间
        while (left < right)
        {
            mid = (left + right) / 2;
            if (nums[left] == target)
                return left;
            if (nums[right] == target)
                return right; //确定边界是否为target
            if (target == nums[mid])
                return mid;
            if (nums[left] < nums[mid]) //如果左边为有序序列
            {
                if (target > nums[left] && target < nums[mid]) //如果target在左边有序序列中
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            //如果右边为有序序列
            else
            {
                if (target > nums[mid] && target < nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        if (nums[left] == target) //当left等于right判断此值是否为target
            return left;
        else
            return -1;
    }
};

class Solution_1
{
  public:
    // 不要被“旋转”而迷惑，“有序”并不是二分查找的核心
    // 二分查找的核心是"通过界桩快速决定查找方向，大幅缩短查找空间"
    // 只要能快速确定界桩，就能使用二分查找
    // 充分利用有序数组能够快速获取边界值的特性
    // 利用这一特性可以快速确定目标值应处的区间
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;
        int lo = 0, hi = nums.size() - 1;

        while (lo <= hi)
        {
            int mi = lo + ((hi - lo) >> 1);
            if (nums[mi] == target)
                return mi;

            // 只要在普通的二分查找判断语句中加一层 && 来确定目标值所在的区间，即可以同样O(logn)的复杂度查找
            if (nums[lo] <= nums[mi] && (nums[lo] <= target && target < nums[mi]))
                hi = mi - 1;
            else if (nums[mi] <= nums[hi] && !(nums[mi] < target && target <= nums[hi]))
                hi = mi - 1;
            else
                lo = mi + 1;
        }
        return -1;
    }
};