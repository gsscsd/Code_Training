/**
实现 atoi，将字符串转为整数。
该函数首先根据需要丢弃任意多的空格字符，直到找到第一个非空格字符为止。如果第一个非空字符是正号或负号，选取该符号，
并将其与后面尽可能多的连续的数字组合起来，这部分字符即为整数的值。如果第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数。
字符串可以在形成整数的字符后面包括多余的字符，这些字符可以被忽略，它们对于函数没有影响。
当字符串中的第一个非空字符序列不是个有效的整数；或字符串为空；或字符串仅包含空白字符时，则不进行转换。
若函数不能执行有效的转换，返回 0。

说明：
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。如果数值超过可表示的范围，则返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

示例 1:
输入: "42"
输出: 42

示例 2:
输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。

示例 3:
输入: "4193 with words"
输出: 4193
解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。

示例 4:
输入: "words and 987"
输出: 0
解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。

示例 5:
输入: "-91283472332"
输出: -2147483648
解释: 数字 "-91283472332" 超过 32 位有符号整数范围。 
     因此返回 INT_MIN (−231) 。
*/

/**
解题思路：
循环遍历慢慢处理 
是否可以考虑递归呢？
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
  public:
    int myAtoi(string str)
    {
        long result = 0;
        int p_n = 1;
        int i = 0, len = str.length();
        // 设计一个bool值，用来表示前面的空格
        bool flag = true;
        cout << " len is " << len << endl;
        while (i < len)
        {
            cout << " i " << i << endl;
            if (flag && str[i] == ' ')
                i++;
            // 如果碰见了减号
            if (flag && str[i] == '-')
            {
                i++;
                flag = false;
                p_n = -1;
            }
            // 如果是碰见了加号
            if (flag && str[i] == '+')
            {
                i++;
                flag = false;
                p_n = 1;
            }
            // 如果碰见是数字字符，那么就相加
            if (str[i] >= '0' && str[i] <= '9')
            {
                cout << "p_n " << p_n << i << " " << str[i] << endl;
                flag = false;
                result = result * 10 + (str[i] - '0');
                if (p_n * result >= INT32_MAX)
                {
                    result = INT_MAX;
                    break;
                }
                if (p_n * result <= INT32_MIN)
                {
                    result = INT32_MIN;
                    break;
                }
                i++;
            }
            // 如果是其他字符，直接跳出
            if (flag && (str[i] != ' ') && (str[i] < '0' || str[i] > '9'))
            {
                break;
            }
            if (!flag && (str[i] < '0' || str[i] > '9'))
            {
                break;
            }
        }
        return (int)result * p_n;
    }
};

// 大神的代码
class Solution_
{
  public:
    // 使用了api
    int myAtoi(string str)
    {
        int flag = 1;
        // 寻找到第一个空格符？
        int i = str.find_first_not_of(' ');
        if (str[i] == '+' || str[i] == '-')
            flag = (str[i++] == '-') ? -1 : 1;
        long sum = 0;
        while (str[i] >= '0' && str[i] <= '9')
        {
            sum = sum * 10 + (str[i++] - '0');
            if (sum * flag >= INT_MAX)
                return INT_MAX;
            if (sum * flag <= INT_MIN)
                return INT_MIN;
        }
        return sum * flag;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
