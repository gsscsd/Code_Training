/**
给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。

说明：不要使用任何内置的库函数，如  sqrt。

示例 1：

输入：16
输出：True
示例 2：

输入：14
输出：False
*/

/**
解题思路：
迭代还是递归呢？
公式计算？？
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution 
{
    public:
        bool isPerfectSquare(int num) 
        {
            if(num <= 1) return true;
            int temp = num / 2;
            for(int i = 0; i <= temp ;++i)
            {
                if(i * i == num) return true;
                if(i * i > num) return false;
            }
            return false;
        }
};

// 没看懂解题的方法是啥？？？？
class Solution_ {
public:
    bool isPerfectSquare(int num) {
        int temp = num;
        int i = 1;
        while(temp > 0)
        {
            temp -= i;
            i += 2;
        }
        if(!temp)
            return true;
        return false;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
