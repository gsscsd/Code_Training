/**
给定一个正整数，输出它的补数。补数是对该数的二进制表示取反。
注意:
给定的整数保证在32位带符号整数的范围内。
你可以假定二进制数不包含前导零位。
示例 1:
输入: 5
输出: 2
解释: 5的二进制表示为101（没有前导零位），其补数为010。所以你需要输出2。
示例 2:
输入: 1
输出: 0
解释: 1的二进制表示为1（没有前导零位），其补数为0。所以你需要输出0。
*/

/**
解题思路：
*/

#include <iostream>
#include <vector>
#include <cmath>


using namespace std;


class Solution 
{
    public:
        int findComplement(int num) 
        {
            int res = 0;
            int i = 0;
            while(num)
            {
                // 先取最后一位，然后和1异或,或者取反
                short c = (num & 1) ^ 1;
                // short c = !(num & 1);
                num >>= 1;
                res += c * pow(2,i);
                i++;
            }
            return res;

        }
};

// 另一种计算方法
// 这种方法才是题目希望的解法
class Solution_ {
public:
    int findComplement(int num) {
        
        int temp = num,n = 1;
        while(num)
        {
            num >>= 1;
            n <<= 1;
        }
        // 这里不太明白为啥要temp ^ (n - 1);
        // 写一下代码就明白了
        return temp ^ (n-1);
    }
};