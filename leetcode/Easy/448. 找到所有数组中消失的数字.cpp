/**
给定一个范围在 1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
找到所有在 [1, n] 范围之间没有出现在数组中的数字。
您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

示例:
输入:
[4,3,2,7,8,2,3,1]
输出:
[5,6]
*/

/**
解题思路：
将所有正数为置为相反数。那么，出现正数的位置即为消失的数字。比如，[4,3,2,7,8,2,3,1]
重置后将为[-4,-3,-2,-7,8,2,-3,-1]
[8,2] 分别对应的index为[5,6]
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) 
        {
            vector<int> vec;
            for(int i = 0;i < nums.size();i++)
            {
                nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
            }
            for(int i = 0 ;i < nums.size();i++)
            {
                if(nums[i] >= 0) vec.push_back(i + 1);
            }
            return vec;
        }
};


int main()
{
    return 0;
}