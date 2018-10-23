/**
颠倒给定的 32 位无符号整数的二进制位。

示例:
输入: 43261596
输出: 964176192
解释: 43261596 的二进制表示形式为 00000010100101000001111010011100 ，
     返回 964176192，其二进制表示形式为 00111001011110000010100101000000 。
*/

/**
解题思路：
移位运算以及考虑是否越界呢？
由于是无符号32位的整数，所以，考虑用移位来运算
通过移位分解成二进制字符串，然后对字符串进行转成10进制
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>

using namespace std;

typedef unsigned int uint32_t;

class Solution
{
    public:
        uint32_t reverseBits(uint32_t n) 
        {
            string res = "";
            while(n)
            {
                int temp = n & 1;
                res += to_string(temp);
                n >>= 1;
            }
            // 如果不足32位就补全
            if(res.size() < 32)
            {
                string st(32 - res.size(),'0');
                res += st;
            }
            cout << " res is " << res << endl;
            // 接下来就是将二进制的字符串转成uint32的数字
            uint32_t result = 0;

            for(int i = res.size() - 1;i>= 0;i--)
            {
                result += (res[i] - '0') * pow(2,31 - i);
            }
            return result;
        }

};

// 更加简洁和高效的算法
// 对于位运算有很深的考虑啊
class Solution_ {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        for(int i = 0;i < 32;i++){
            m <<= 1;
            // 这里的代码没有明白什么意思呢？
            // 这里的或是什么意思呢？
            m = m | (n & 1);
            n >>= 1;
        }
        return m;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    uint32_t n;
    cin >> n;
    uint32_t t = s.reverseBits(n);
    cout << t << endl;
    
    return 0;
}
