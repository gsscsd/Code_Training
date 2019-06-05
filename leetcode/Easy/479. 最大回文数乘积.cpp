/**
你需要找到由两个 n 位数的乘积组成的最大回文数。
由于结果会很大，你只需返回最大回文数 mod 1337得到的结果。
示例:
输入: 2
输出: 987
解释: 99 x 91 = 9009, 9009 % 1337 = 987
说明:
n 的取值范围为 [1,8]。
*/

/**
解题思路：
1.首先暴力计算
2.先算出两个位数相同的数相乘的最大积，
将最大积分成左右两半，根据左半边来构造回文数。将回文数构造出来之后，对乘数从大到小进行遍历。
如果回文数刚好能整除乘数，则说明这就是我们要找的那个最大回文积，
最后直接将这个回文积模1337就是我们所要的结果；如果不能整除，
则乘数减1重新进行判断，直到乘数的平方小于回文数。

*/

#include <iostream>
#include <vector>
#include <cmath>


using namespace std;


class Solution 
{
    public:
        // 判断是否是回文数
       int largestPalindrome(int n) {
        //  计算给定位的最大数的上下边界
        // 得到上限是uupper，下限是lower
        int upper = pow(10, n) - 1, lower = upper / 10;

        for(int i = upper; i > lower; i--) 
        {
            string t = to_string(i);
            // 字符串类型转long类型，同时构造回文数，rbegin反向寻找字符边界
            // 建立2n位的回文数，比如i=99，那么建立的回文数是9999，比如i=98，建立的回文数9889，构造回文序列。
            long p = stol(t + string(t.rbegin(), t.rend()));
            // 接下来从上边界寻找构成回文数的因数
            // 判断得到的回文数是否能整除n位的数字
            for(long j = upper; j * j > p; j--) 
            {
                if(p % j == 0) 
                {
                    return p % 1337;
                }
            }
        }
        return 9;
    }
};