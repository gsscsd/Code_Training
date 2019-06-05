/***
给定一个整数，将其转化为7进制，并以字符串形式输出。
示例 1:
输入: 100
输出: "202"
示例 2:
输入: -7
输出: "-10"
注意: 输入范围是 [-1e7, 1e7] 。
*/

/**
解题思路：
除n取余法
*/

#include <vector>
#include <cmath>
#include <iostream>


using namespace std;


class Solution 
{
    public:
        string convertToBase7(int num) 
        {
            if(!num) return "0";
            string res = "";
            char ch[7] = {'0','1','2','3','4','5','6'};
            bool flag = false;
            if(num < 0)
            {
                flag = true;
                num = -num;
            }
            while(num)
            {
                res = ch[num % 7] + res;
                num /= 7;
            }
            if(flag) res = "-" + res;
            return res;
        }
};