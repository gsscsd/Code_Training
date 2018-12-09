/**
给定一个整数，写一个函数来判断它是否是 3 的幂次方。

示例 1:
输入: 27
输出: true

示例 2:
输入: 0
输出: false

示例 3:
输入: 9
输出: true

示例 4:
输入: 45
输出: false
进阶：
你能不使用循环或者递归来完成本题吗？
*/

/**
解题思路：
直接递归或者迭代来处理
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
    public:
        bool isPowerOfThree(int n) 
        {
            if(n == 0) return false;
            // 如果n能整除3，则
            while(!(n % 3))
            {
                n /= 3;
            }
            if(n == 1) return true;
            return false;
        }
};

//这个是用数学公式求log的方法
// 所以这里就是不用循环的方法喽
class Solution_ {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        double tmp = log10(n) / log10(3);
        if (tmp - int(tmp) == 0)
            return true;
        return false;
    }
};