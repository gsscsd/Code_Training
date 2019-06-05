/**
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
说明:

可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
你算法的时间复杂度应该为 O(n2) 。
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗? 
*/

/**
解题思路：
动态规划：O(n^2)
贪心+二分：O(nLogN)
*/

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {

        if (nums.size() <= 0)
            return 0;
        int n = nums.size();
        int *dp = new int[n];
        int inf = 0x7fffffff;
        fill(dp, dp + n, inf);
        for (int i = 0; i < n; i++)
        {
            *lower_bound(dp, dp + n, nums[i]) = nums[i];
        }
        return lower_bound(dp, dp + n, inf) - dp;
    }
};

// 二分查找的方法，和上面的方法类似
class Solution_1
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        /**
        dp[i]: 所有长度为i+1的递增子序列中, 最小的那个序列尾数.
        由定义知dp数组必然是一个递增数组, 可以用 maxL 来表示最长递增子序列的长度. 
        对数组进行迭代, 依次判断每个数num将其插入dp数组相应的位置:
        1. num > dp[maxL], 表示num比所有已知递增序列的尾数都大, 将num添加入dp
           数组尾部, 并将最长递增序列长度maxL加1
        2. dp[i-1] < num <= dp[i], 只更新相应的dp[i]
        **/
        int maxL = 0;
        int n = nums.size();
        int *dp = new int[n];
        fill(dp,dp+n,0);
        for (int num : nums)
        {
            // 二分法查找, 也可以调用库函数如binary_search
            int lo = 0, hi = maxL;
            // 二分查找
            while (lo < hi)
            {
                int mid = lo + (hi - lo) / 2;
                if (dp[mid] < num)
                    lo = mid + 1;
                else
                    hi = mid;
            }
            dp[lo] = num;
            if (lo == maxL)
                maxL++;
        }
        return maxL;
    }
};

// 基于动态规划的方法
class Solution_2
{
public:
    int lengthOfLIS(vector<int> &nums)
    {

        if (nums.size() <= 0)
            return 0;
        int n = nums.size();
        int *dp = new int[n];
        fill(dp, dp + n, 1);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        for(int i = 0;i < n;i++)
            res = max(res,dp[i]);
        return res;
    }
};