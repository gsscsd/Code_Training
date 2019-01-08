/**
不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。

示例 1:
输入: a = 1, b = 2
输出: 3

示例 2:
输入: a = -2, b = 3
输出: 1

*/

/**
解题思路：
是否使用与或非呢？
*/

#include <iostream>
#include <vector>
#include <map>


using namespace std;


// 但是没有看懂题目呢？？？
class Solution 
{
    public:
        int getSum(int a, int b) 
        {
            while(b)
            {
                int c = a;
                a = a^b;
                b = (c & b) << 1;
            }
            return a;
        }
};

int main(int argc, char const *argv[])
{
    return 0;
}
