/**
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:
输入: 1
输出: true
解释: 2^0 = 1

示例 2:
输入: 16
输出: true
解释: 2^4 = 16

示例 3:
输入: 2^18
输出: false
*/

/**
解题思路：
一开始的思路考虑是否是快速幂算法
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
    public:
        // 用除法来做
        bool isPowerOfTwo(int n) 
        {
            // 注意负数和0
            if(n <= 0) return false;
            // 注意这里的while的判断
            while(n != 1)
            {
                if(n % 2 != 0) return false;
                n /= 2;
            }
            return n == 1 ? true : false;
        }
};
// 大神的代码，依然这么简洁
class Solution_ {
public:
    bool isPowerOfTwo(int n) {
        if ( n <= 0 ) return false;
        // 这里的代码没有明白是什么意思？
        return (n & -n) == n;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    int n = 1073741825;
    bool b = s.isPowerOfTwo(n);
    cout << " bool is " << b << endl;
    
    return 0;
}


