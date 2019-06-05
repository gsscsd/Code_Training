/**

给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。

示例 1:

输入: 16
输出: true
示例 2:

输入: 5
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？
*/

/**
解题思路：
4的幂一定是2的幂，因此可以转化为2的幂的方法来做
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 通过数学公式来计算的
class Solution 
{
    public:
        bool isPowerOfFour(int num) 
        {
            if (num <= 0)
                return false;
            double tmp = log10(num) / log10(4);
            if (tmp - int(tmp) == 0)
                return true;
            return false;
        }
};

// 大神的代码，很神奇
class Solution_ {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && (num & 0x55555555) == num;
    }
};


