/**
对于一个 正整数，如果它和除了它自身以外的所有正因子之和相等，我们称它为“完美数”。
给定一个 正整数 n， 如果他是完美数，返回 True，否则返回 False

示例：
输入: 28
输出: True
解释: 28 = 1 + 2 + 4 + 7 + 14
注意:
输入的数字 n 不会超过 100,000,000. (1e8)
*/

/**
解题思路： 
递归或者迭代计算
*/

#include <vector>
#include <cmath>

using namespace std;

class Solution 
{
    public:
        bool checkPerfectNumber(int num) 
        {
            if(num == 0 || num == 1) return false;
            int sum = num;
            // 这里的循环需要优化
            for(int i = 1; i < num;i++)
            {
                if(isFactor(i,num))
                {
                    sum -= i;
                }
            }
            return sum == 0 ? true:false;
        }
        bool isFactor(int n,int num)
        {
            return num % n == 0 ? true:false;
        }
    
};

// 大神的代码，主要的思路是加和计算
class Solution_ 
{
    public:
    bool checkPerfectNumber(int num) {
        int ans = 1;
        for(int i = 2;i <= sqrt(num);i++)
        {
            if(num % i == 0)
                ans = ans + i + num/i;
        }
        if(num == 1 || num == 0)
            return false;
        if(ans == num)
            return true;
        return false;
    }
};
