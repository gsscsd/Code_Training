/**
你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。
给定一个数字 n，找出可形成完整阶梯行的总行数。
n 是一个非负整数，并且在32位有符号整型的范围内。

示例 1:
n = 5
硬币可排列成以下几行:
¤
¤ ¤
¤ ¤
因为第三行不完整，所以返回2.
示例 2:
n = 8
硬币可排列成以下几行:
¤
¤ ¤
¤ ¤ ¤
¤ ¤
因为第四行不完整，所以返回3.
*/
/**
解题思路：
1.数学规律：等差数列的求和
    已知等差数列求和公式n = (1 + x) * x / 2，那么等式变换可得x = (-1 + sqrt(8 * n + 1)) / 2.
2.二分查找
但是都需要注意，会溢出
*/

#include <vector>
#include <cmath>

using namespace std;

class Solution 
{
    public:
        int arrangeCoins(int n) 
        {
            // 数学公式会溢出
            // return (-1 + sqrt(8 * n + 1)) / 2
            // 数学公式结果，这样的不会溢出
            // return (int)(-1 + sqrt(1 + (long)n << 3)) >> 1;
            for(int i = 1; ; i++)
            {
                if(n < i)
                {
                    return i - 1;
                }
                if(n == i)
                {
                    return i;
                }
                n -= i;
            }
            return -1;
        }
};


int main(int argc, char const *argv[])
{
    return 0;
}
