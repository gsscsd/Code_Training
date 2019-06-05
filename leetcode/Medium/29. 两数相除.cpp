/**
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
说明:

被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。
本题中，如果除法结果溢出，则返回 2^31 − 1。
*/

/**
解题思路：
位运算
1）负数的表示方法（最高位为1，减去其余位） 
2）使用左移形成2的指数倍，加快运算。
显然，用对数和幂运算性质，有 y/x=e^(lny-lnx)。先把除数和被除数取绝对值，divide = exp(log(dividend) - log(divisor))。
如果取正后，溢出，则先把原来的数右移 / 左移一位，计算后，把结果再左移 / 右移一位。注意精度问题。
*/
/**
 * 解题思路：这题是除法，所以先普及下除法术语
 * 商，公式是：(被除数-余数)÷除数=商，记作：被除数÷除数=商...余数，是一种数学术语。
 * 在一个除法算式里，被除数、余数、除数和商的关系为：(被除数-余数)÷除数=商，记作：被除数÷除数=商...余数，
 * 进而推导得出：商×除数+余数=被除数。
 *
 * 要求商，我们首先想到的是减法，能被减多少次，那么商就为多少，但是明显减法的效率太低
 *
 * 那么我们可以用位移法，因为计算机在做位移时效率特别高，向左移1相当于乘以2，向右位移1相当于除以2
 *
 * 我们可以把一个dividend（被除数）先除以2^n，n最初为31，不断减小n去试探,当某个n满足dividend/2^n>=divisor时，
 *
 * 表示我们找到了一个足够大的数，这个数*divisor是不大于dividend的，所以我们就可以减去2^n个divisor，以此类推
 *
 * 我们可以以100/3为例
 *
 * 2^n是1，2，4，8...2^31这种数，当n为31时，这个数特别大，100/2^n是一个很小的数，肯定是小于3的，所以循环下来，
 *
 * 当n=5时，100/32=3, 刚好是大于等于3的，这时我们将100-32*3=4，也就是减去了32个3，接下来我们再处理4，同样手法可以再减去一个3
 *
 * 所以一共是减去了33个3，所以商就是33
 *
 * 这其中得处理一些特殊的数，比如divisor是不能为0的，Integer.MIN_VALUE和Integer.MAX_VALUE
 *
*/

#include <iostream>
#include <cmath>

using namespace std;

#define INT32_MAX 2147483647
#define INT32_MIN -2147483648
#define INT_MAX 0X7FFFFFFF
#define INT_MIN 0X80000000

// 解法一：使用数学公式来做
// 没有做出来？？？
class Solution
{
  public:
    int divide(int dividend, int divisor)
    {
        // 首先将除数和被除数变成正数
        if (dividend == INT32_MIN && divisor == -1)
            return INT32_MAX;
        long absdivisor = abs((long)divisor);
        long absdividend = abs((long)dividend);
        uint32_t res = exp(log(absdividend) - log(absdivisor));
        if (divisor < 0 && dividend < 0)
            return res > INT_MAX ? INT_MAX : res;
        if (divisor < 0 || dividend < 0)
            return -res > INT_MIN ? INT_MIN : res;
        return res > INT_MAX ? INT_MAX : res;
    }
};

// 解法二：
// 迭代计算
class Solution
{
  public:
    int divide(int dividend, int divisor)
    {
        if (divisor == 1)
            return dividend;
        if (dividend == INT_MIN && divisor == -1)
            return INT32_MAX;
        long long absdividend = abs((long long)dividend), absdivisor = abs((long long)divisor), res = 0;
        // 判断dividend和divisor是否同号
        int sign = (dividend < 0) ^ (divisor < 0);
        // 循环寻找最接近的两个数
        for (int i = 31; i >= 0; i--)
        {
            if ((absdividend >> i) >= absdivisor)
            {                                   //找出足够大的数2^n*divisor
                res += 1 << i;                  //将结果加上2^n
                // 以下这句代码很巧妙
                absdividend -= absdivisor << i; //将被除数减去2^n*divisor,接着从新迭代计算
            }
        }
        return sign ? -res:res;
    }
};
