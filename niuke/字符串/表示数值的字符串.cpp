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
        bool isNumeric(char* str)
        {
                int str_len = strlen(str);
                if(str_len <= 0) return false;
                
                // 标记符号、小数点、e是否出现过
                bool sign = false, decimal = false, hasE = false;
                int i = 0;
                while(*str != '\0')
                {
                        if(*str == 'e' || *str == 'E')
                        {
                                if(*(str + 1) == '\0') return false;
                                if(hasE) return false;
                                hasE = true;
                        }
                        else if(*str == '+' || *str == '-')
                        {
                                if(sign && *(str - 1) != 'e' && *(str - 1) != 'E') return false;
                                if(!sign && i > 0 && *(str - 1) != 'e' && *(str - 1) != 'E') return false;
                                sign = true;
                        }
                        else if(*str == '.')
                        {
                                if(hasE || decimal) return false;
                                decimal = true;
                        }
                        else if(*str < '0' || *str > '9')
                        {
                                return false;
                        }
                        i++;
                        str++;
                }
                return true;
        }

        // 高票答案
        // 思路比较清晰
        // 基本思路是排除错误的可能性，也就是找正确性
        bool isNumeric_(char* str) {
                // 标记符号、小数点、e是否出现过
                bool sign = false, decimal = false, hasE = false;
                for (int i = 0; i < strlen(str); i++) {
                        if (str[i] == 'e' || str[i] == 'E') {
                                // 如果e在最后面那么返回false
                                if (i == strlen(str)-1) return false; // e后面一定要接数字
                                if (hasE) return false;  // 不能同时存在两个e
                                hasE = true;
                        } else if (str[i] == '+' || str[i] == '-') {
                                // 第二次出现+-符号，则必须紧接在e之后
                                if (sign && str[i-1] != 'e' && str[i-1] != 'E') return false;
                                // 第一次出现+-符号，且不是在字符串开头，则也必须紧接在e之后
                                if (!sign && i > 0 && str[i-1] != 'e' && str[i-1] != 'E') return false;
                                sign = true;
                        } else if (str[i] == '.') {
                        // e后面不能接小数点，小数点不能出现两次
                                if (hasE || decimal) return false;
                                decimal = true;
                        } else if (str[i] < '0' || str[i] > '9') // 不合法字符
                                return false;
                }
                return true;
        }
};



int main(int argc, char const *argv[])
{

        char *ss = "100";
        // char ss;
        // cin >> ss;
        Solution s;
        bool b = s.isNumeric(ss);
        cout << b << endl;
        return 0;
}

