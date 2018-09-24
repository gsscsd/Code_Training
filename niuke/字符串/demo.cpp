/**
题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。 
*/

/***

思路：1、首先判断正负号，如果是否为空或\0，返回false。
2、扫描所有数字，如果还没到结尾。若此时是.则证明是浮点型数，继续扫描数字，如果碰到e或者E还需要判断后续是否合法
3、若扫描的不是.那么若是e或者E则进行后续判断，如果也不是e或者E就直接返回错误
4、正确的条件是numeric为true且string扫描到了末尾 
*/


#include <iostream>
#include <vector>
// #include <string>
#include <cstring>



using namespace std;


class Solution {
public:
        bool isNumeric(char* string)
        {
                int str_len = strlen(string);
                if(str_len <= 0) return false;
                
                // 标记符号、小数点、e是否出现过
                bool sign = false, decimal = false, hasE = false;
                // for(int i = 0; i < )


        }

};



int main(int argc, char const *argv[])
{
        return 0;
}

