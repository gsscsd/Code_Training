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
分析5,题目肯定与5有关,需要归纳计算:
推导公式：
令f(x)表示正整数x末尾所含有的“0”的个数，则有：
   当0 < n < 5时，f(n!) = 0;
   当n >= 5时，f(n!) = k + f(k!), 其中 k = n / 5（取整）。
   
f(5!) = 1 + f(1!) = 1
f(10!) = 2 + f(2!) = 2
f(20!) = 4 + f(4!) = 4
f(100!) = 20 + f(20!) = 20 + 4 + f(4!) = 24
f(1000!) = 200 + f(200!) = 200 + 40 + f(40!) = 240 + 8 + f(8!) = 248 + 1 + f(1) =249
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
            while(n)
            {
                result +=  (n = n / 5);
            }
            return result;
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


