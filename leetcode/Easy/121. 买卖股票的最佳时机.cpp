/**
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
注意你不能在买入股票前卖出股票。

示例 1:
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。

示例 2:
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
*/

/**
解题思路

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
    public : 
        // 最简单的方法是两层for循环
        // leetcode的标准解法是O(n)
        int maxProfit(vector<int> &nums)
        {
            // 边界判断
            if(nums.size() <= 1) return 0;
            // 保存最大的收益
            int max_profit = 0;
            // 保存最小值
            int min_num = nums[0];
            for(int i = 0;i < nums.size();i++)
            {
                // // 找到最小的值
                // if(nums[i] < min_num)  min_num = nums[i];
                // // 否则的话，计算最大收益
                // else 
                // {
                //     if(max_profit <= nums[i] - min_num) max_profit = nums[i] - min_num;
                // }
                // 以上的代码，可以用api来代替
                min_num = min(nums[i],min_num);
                max_profit = max(nums[i] - min_num,max_profit);
            }
           return max_profit; 
        }
};


int main()
{
    return 0;
}



