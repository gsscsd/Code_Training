/**
编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。

示例 :
输入: 11
输出: 3
解释: 整数 11 的二进制表示为 00000000000000000000000000001011
 
示例 2:
输入: 128
输出: 1
解释: 整数 128 的二进制表示为 00000000000000000000000010000000
*/


/**
解题思路：
剑指offer的简化题目
考察移位以及位运算  
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
    public:
        int hammingWeight(uint32_t n) 
        {
            // 直接进行移位操作，并且去&1
            int res = 0;
            while(n)
            {
                res += (n & 1);
                n >>= 1;
            }
        }
};


 int main(int argc, char const *argv[])
 {
     
    return 0;
 }
 