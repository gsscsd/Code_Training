/**
给定一个Excel表格中的列名称，返回其相应的列序号。

例如，
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

示例 1:
输入: "A"
输出: 1

示例 2:
输入: "AB"
输出: 28

示例 3:
输入: "ZY"
输出: 701
*/

/**
解题思路：
168题目的逆，其实就是26进制转换成10进制
是对其他进制转换的扩展
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>

using namespace std;


class Solution 
{
    public:
        // 26进制转换成10进制
        int titleToNumber(string s)
        {
            int res = 0;
            int s_len = s.size();
            if(s_len < 1) return 0;
            // 注意此处的代码，是从低位向高位计算的
            for(int i = s_len - 1;i >= 0;i--)
            {
                int temp = (s[i] - 'A' + 1) * pow(26,s_len - 1 - i);
                res += temp;
            }
            return res;
        }
};


int main()
{
    return 0;
}