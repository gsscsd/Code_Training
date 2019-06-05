/**
求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
*/

/**
解题思路：
当计算右数第 i 位包含的 X 的个数时：
取第 i 位左边（高位）的数字，乘以 10i−1，得到基础值 a。
取第 i 位数字，计算修正值：
如果大于 X，则结果为 a+10i−1。
如果小于 X，则结果为 a。
如果等 X，则取第 i 位右边（低位）数字，设为 b，最后结果为 a+b+1。

博客地址：http://www.cnblogs.com/cyjb/p/digitOccurrenceInRegion.html
*/

#include <vector>
#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    // 参考自编程之美的博客
    int NumberOf1Between1AndN_Solution(int n)
    {
        int cnt = 0,k;
        for(int i = 1;k = (n / i);i *= 10)
        {
            cnt += (k / 10) * i;
            int cur = k % 10;
            if(cur > 1)
            {
                cnt += i;
            }
            else if(cur == 1)
            {
                cnt += n - k * i + 1;
            }
        }
        return cnt;
        
    }
    // PS:参考博客写一个通用的框架，
    // 计算从[1,n]区间中X出现的次数，X不包含0
    int countX(int n,int x)
    {
        int cnt = 0,k;
        for(int i = 1;k = (n / i);i *= 10)
        {
            // 计算高位数的X出现的次数
            cnt += ( k / 10) * i;
            // 计算当前位上的数
            int cur = k % 10;
            // 如果，当前位上的数大于X，那么，还需要加上i
            if( cur > x)
            {
                cnt += i;
            }
            // 如果是等于x,那么加上低位上数字的数目且加1
            else if(cur == x)
            {
                cnt += n - k * i + 1;
            }
        }
        return cnt;
    }
    // 计算数字 X 在 1-n 中出现的次数。
    // 优化后的代码，处理了X包含0的情况
    int count(int n, int x) {
        int cnt = 0, k;
        for (int i = 1;k = n / i;i *= 10) {
            // 高位的数字。
            int high = k / 10;
            if (x == 0) {
                if (high) {
                    high--;
                } else {
                    break;
                }
            }
            cnt += high * i;
            // 当前位的数字。
            int cur = k % 10;
            if (cur > x) {
                cnt += i;
            } else if (cur == x) {
                // n - k * i 为低位的数字。
                cnt += n - k * i + 1;
            }
        }
        return cnt;
    }

};

int main()
{

}