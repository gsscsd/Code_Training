/**
题目描述
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，
要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0。
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
*/

/**
解题思路
*/
#include <iostream>
#include <string>
#include <cstring>


using namespace std;



class Solution {
public:
    int StrToInt(string str) {

        // 防止数字太大过于溢出
        long result = 0;
        // 首先判断长度的边界
        int str_len = str.length();
        if(str_len <= 0) return result;
        bool flag = true;
        // s 来代表符号位
        int s = 1;
        // 判断第一个字符是正负号
        if(str[0] == '-') s = -1;
        // 注意此处的代码，通过三元表达式来决定如何遍历
        for(int i = (str[0] ==  '-' || str[0] == '+') ? 1 : 0;i < str_len;i++)
        {
                if(str[i] >= '0' && str[i] <= '9') result = result * 10 + str[i] - '0';
                else return 0;
        }
        return result * s; 
    }
};


int main(int argc, char const *argv[])
{
        
        return 0;
}
