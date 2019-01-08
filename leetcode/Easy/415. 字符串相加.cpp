/**
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：
num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
*/


/**
解题思路
在前面碰见过的题目
参见题目67二进制求和
*/

#include <string>
#include <iostream>


using namespace std;

class Solution 
{
    public:
        string addStrings(string num1, string num2) 
        {
            string res = "";
            int i = num1.length() - 1,j = num2.length() - 1;
            int flag = 0;
            while(i >= 0 || j >= 0)
            {
                int at = (i >= 0) ? num1[i] - '0' : 0;
                int bt = (j >= 0) ? num2[j] - '0' : 0;
                
                int temp = at + bt + flag;
                flag = temp / 10;

                res = to_string(temp % 10) + res;
                --i,--j;
            }
            if(flag) res = "1" + res;
            return res;
        }
};


int main(int argc, char const *argv[])
{
    return 0;
}
