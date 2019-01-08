/**
在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。
注意:
n 是正数且在32为整形范围内 ( n < 2^31)。
示例 1:
输入:
3
输出:
3
示例 2:
输入:
11
输出:
0
说明:
第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。
*/


/**
解题思路:
睿智的题目
笔记】主要分为两部分，首先计算前缀部分，再计算尾部。

1. 小于10，直接返回。(step 1)
2. 否则，计算前缀部分，全部被占用部分总共有多少位即length。(step 2)
3. 计算尾部，其一、计算第一个数字即pow(10, i-1)-1。其二、推理出最后一个出现的多位数字即num，并计算出位于第几位即index。(step 3)
//1234567891011121314151617181920
//1 - [1,9]             9
//2 - [10,99]          90
//3 - [100,999]       900
//4 - [1000,9999]    9000
//.........2^31 = 2147483648
另外，需要一点注意int类型会溢出（比如，pow(10,11)就溢出了）需要定义为更大的类型。
*/

#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

// 大神的代码
class Solution_ {
    public:
        int findNthDigit(int n) 
        {
            long long cnt = 1, base = 9, sum = 0;
            sum += cnt * base;
            while (sum < n)
            {
                cnt++;
                base *= 10;
                sum += cnt * base;
            }
            sum -= cnt * base;
            n -= sum;
            if (cnt == 1)
            {
                return n;
            }
            string s = to_string((n + 1) / cnt + pow(10, cnt - 1) - 1);
            long long index = (n - 1) % cnt;
            return s[index] - '0';
        }
};



int main(int argc, char const *argv[])
{
    return 0;
}
