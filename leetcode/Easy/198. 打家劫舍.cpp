/**
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:
输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。

示例 2:
输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
*/
/**
解题思路：
哔哩哔哩up主：正月点灯笼讲过的一个动态规划的例子
所以此题可以用动态规划来做
需要考虑的几个点
1.边界条件如何限定
2.状态转移方程如何分析
在分析的时候，从后面向前分析，然后在从前向后写代码
快速的理解动态规划就在于需要一个空间数组来保存以前的数据
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

// 使用宏定义一个最大值函数
#define MAX(x,y) x > y ? x : y

class Solution 
{
    public:
        int rob(vector<int>& nums) 
        {
                int n = nums.size();
                vector<int> vec(n);
                if(n == 0) return 0;
                if(n == 1) return nums[0];
                if(n == 2) return max(nums[0],nums[1]);
                // 注意这里的前面的两个数的赋值，没有考虑到
                vec[0] = nums[0];
                // 这里需要注意一下，因为vec是用来保存前k个的最大值
                vec[1] = max(nums[0],nums[1]);
                // 存在好几个间隔的情况
                for(int i = 2;i < n;i++)
                {
                        vec[i] = max(nums[i] + vec[i - 2],vec[i - 1]);
                }
                return vec[n - 1];
        }
};

// 另一种动态规划的方法
class Solution_ {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        // 定义这个数组是为了什么呢
        // 定义了一个二维的数组，dp[][0]保存不取当前元素的最大值,dp[][1]保存取当前元素的最大值
        int dp[n+1][2];
        // 对数组进行清零
        memset(dp, 0, sizeof(dp));
        dp[0][1] = nums[0];
        // 没太理解这里的for循环是啥意思？
        // 递归计算最大值
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i][0], max(dp[i-1][1], dp[i-1][0]));
            dp[i][1] = max(dp[i][1], dp[i-1][0]+nums[i]);
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};


int main(int argc, char const *argv[])
{
        vector<int> vec;

        vec.push_back(2);
        vec.push_back(7);
        vec.push_back(9);
        vec.push_back(3);
        vec.push_back(1);

        Solution s;
        int t = s.rob(vec);
        cout << " the max num is " << t << endl;

        return 0;
}

