/**
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:
输入: 2.00000, 10
输出: 1024.00000
示例 2:
输入: 2.10000, 3
输出: 9.26100
示例 3:
输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:
-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/powx-n
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
解题思路：
1.暴力
2.快速幂算法
*/

#include <bits/stdc++.h>

using namespace std;

// 第一种，暴力的方法
class Solution1
{
public:
    double myPow(double x, int n)
    {
        long long N = n;
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        for (long long i = 0; i < N; i++)
            ans = ans * x;
        return ans;
    }
};

// 第二种快速幂算法
// 递归的快速幂算法
class Solution2
{
public:
    double fastPow(double x, long long n)
    {
        if (n == 0)
        {
            return 1.0;
        }
        double half = fastPow(x, n / 2);
        if (n % 2 == 0)
        {
            return half * half;
        }
        else
        {
            return half * half * x;
        }
    }
    double myPow(double x, int n)
    {
        long long N = n;
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }
};

// 第二种快速幂算法
// 循环快速幂
class Solution3
{
public:
    double myPow(double x, int n)
    {
        long long N = n;
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        double current_product = x;
        while (N > 0)
        {
            if (N & 1)
            {
                ans *= current_product;
            }
            current_product = current_product * current_product;
            N >>= 1;
        }
        return ans;
    }
};
