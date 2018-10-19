/**
给定一个整数 n，返回 n! 结果尾数中零的数量。

示例 1:
输入: 3
输出: 0
解释: 3! = 6, 尾数中没有零。

示例 2:

输入: 5
输出: 1
解释: 5! = 120, 尾数中有 1 个零.
说明: 你算法的时间复杂度应为 O(log n) 。
*/

/**
解题思路：
分析5，以及偶数的个数，如何分析，需要归纳计算
*/

#include <vector>
#include <iostream>

using namespace std;


class Solution
{
    public:
        int trailingZeroes(int n) 
        {
            int result = 0;
            return n / 5;
        }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    cin >> n;
    int t = s.trailingZeroes(n);
    cout << t << endl;
    return 0;
}

