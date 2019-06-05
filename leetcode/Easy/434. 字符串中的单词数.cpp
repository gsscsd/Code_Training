/**
统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
请注意，你可以假定字符串里不包括任何不可打印的字符。
示例:
输入: "Hello, my name is John"
输出: 5
*/

/**
解题思路：
文件流 
*/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


// 简单的方法
class Solution 
{
    public:
        int countSegments(string s) 
        {
            stringstream ss(s);
            string st;
            int count = 0;
            while(ss >> st) count++;
            return count;
        }
};


// 复杂的方法
class Solution_ {
public:
    int countSegments(string s) {
        if (s == "") {
            return 0;
        }
        // 掐头去尾把s前边和后边的所有空格都去掉
        int begin = 0, end = s.length()-1;
        while(s[begin] == ' ' && begin <= end) {
            begin++;
        }
        while(s[end] ==  ' ' && begin <= end) {
            end--;
        }
        
        if (begin > end) {
            return 0;
        }
        
        int count = 0;
        for (int i = begin; i <= end; i++) {
            if (s[i] == ' ') {
                count++;
            }
            while(s[i] == ' ') {
                i++;
            }
        }
        return count + 1;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}


