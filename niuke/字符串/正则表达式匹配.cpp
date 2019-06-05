/**
题目描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式"a.a式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/

/**
 解这题需要把题意仔细研究清楚，这里主要是琢磨透*的意义

分析：递归实现
每次分别在str 和pattern中取一个字符进行匹配，如果匹配，则匹配下一个字符，否则，返回不匹配。
设匹配递归函数 match(str, pattern)。
如果模式匹配字符的下一个字符是‘*’:
        •如果pttern当前字符和str的当前字符匹配，：有以下三种可能情况
        （1）pttern当前字符能匹配 str 中的 0 个字符：match(str, pattern+2)
        //在这里其实2和3这两条规则可以一起来考虑
        （2）pttern当前字符能匹配 str 中的 1 个字符：match(str+1, pattern+2)
        （3）pttern当前字符能匹配 str 中的 多 个字符：match(str+1, pattern)
        •如果pttern当前字符和和str的当前字符不匹配
pttern当前字符能匹配 str 中的 0 个字符：(str, pattern+2)
如果模式匹配字符的下一个字符不是‘*’，进行逐字符匹配。
对于 ‘.’ 的情况比较简单，’.’ 和一个字符匹配 match(str+1, pattern+1)
另外需要注意的是：空字符串”” 和 “.*” 是匹配的
*/

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Solution {
public:
        bool match(char* str, char* pattern)
        {
                // 模式串和字符串都到达尾部，说明匹配成功
                if (*str == '\0' && *pattern == '\0')
                        return true;
                // 字符串未到尾部，模式串到尾部，说明匹配失败
                if (*str != '\0' && *pattern == '\0')
                        return false;
                // 根据pattern下一位是否是*来判断
                if(*(pattern + 1) != '*' )
                {
                        // 如果下一位不是*,并且当前位相当或者存在.，那就递归计算
                        if(*str == *pattern || (*str != '\0' && *pattern == '.'))
                                // 同时向下去移位
                                return match(str+1,pattern + 1);
                        else return false;

                }
                // 如果下一位是*，那么就要按照上面分析的去考虑
                else
                {
                        // 
                        if(*str == *pattern ||(*str != '\0' && *pattern == '.'))
                                // 这里是匹配其他的次数，1次和其他次数
                                return match(str, pattern+2) || match(str+1, pattern);
                        // 这里的else是指当前字符不匹配。跳过带有*的位置
                        else return match(str,pattern + 2);

                }
        }
};


int main(int argc, char const *argv[])
{
        Solution s;
        char *a = "aaab";
        char *b = "a*ab";
        bool t = s.match(a,b);
        cout << "result is " << t << endl;

        return 0;
}
