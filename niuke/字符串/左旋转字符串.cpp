/**
题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，
就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，
请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,
要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
*/
/**
解题思路：
1.直接使用api来做，但是未通过运行
2.循环原地交换
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 利用api来操作
    string LeftRotateString(string str, int n) {
        string s0 = str.substr(0,n);
        string s1 = str.substr(n);
        return s1 + s0; 
    }
    // 手动实现字符旋转
    string LeftRotateString_(string str, int n) {

        char ch;
        int len = str.length();
        for(int i = 0;i < n;++i)
        {
            ch = str[0];
            for(int j = 1;j < str.length();j++)
            {

                str[j - 1] = str[j];
            }
            str[len - 1] = ch;
        }   
        return str;
    }
    // 更加简洁的代码
    string LeftRotateString_1(string str, int n) {
            int len = str.length();
            if(len == 0) return "";
            // 首先计算移位的位数
            n = n % len;
            // 复制字符串的长度
            str += str;
            // 然后直接寻找子串
            return str.substr(n, len);
        }
};

int main()
{
    string str = "abcXYZdef";
    int k = 0;
    cin >> k;
    Solution s;
    string result = s.LeftRotateString_(str,k);
    cout << "result " << result << endl;
    cout << "str is " << str << endl;
}