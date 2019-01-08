/**
给定一个长度为 n 的非空整数数组，找到让数组所有元素相等的最小移动次数。每次移动可以使 n - 1 个元素增加 1。
示例:
输入:
[1,2,3]
输出:
3
解释:
只需要3次移动（注意每次移动会增加两个元素的值）：

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
*/

/**
解题思路：
逆向思考，每次移动让剩余的n-1个数加1，相当于每次移动让选定的那个数减1，
所以最少移动次数其实就是所有元素减去最小元素的和。
*/

#include <vector>
#include <iostream>

using namespace std;


class Solution 
{
    public:
        int minMoves(vector<int>& nums) 
        {
            int sum = 0,minVal = INT32_MAX;
            for(auto i : nums)
            {
                sum += i;
                minVal = min(i,minVal);
            }
            return sum - minVal * nums.size();
        }
};