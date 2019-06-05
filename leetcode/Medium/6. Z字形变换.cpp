/**
将字符串 "PAYPALISHIRING" 以Z字形排列成给定的行数：

P   A   H   N
A P L S I I G
Y   I   R
之后从左往右，逐行读取字符："PAHNAPLSIIGYIR"
实现一个将字符串进行指定行数变换的函数:

string convert(string s, int numRows);

示例 1:
输入: s = "PAYPALISHIRING", numRows = 3
输出: "PAHNAPLSIIGYIR"

示例 2:
输入: s = "PAYPALISHIRING", numRows = 4
输出: "PINALSIGYAHRPI"
解释:
P     I    N
A   L S  I G
Y A   H R
P     I
*/

/**
解题思路：
这个题目不难，但是很难想
不太好想
我们对s = 'PAYPALISHIRING', numRows = 4来进行分析，我们直接写出这个字符串中的每一个字符所处的行数，
则应该是 12343212343212。发现规律一下就找到了,下一个字符的行数取决于前一个字符的行数，要么+1要么-1，
我们定义一个方向dire，向下走是+1，向上走是-1，当走到边界时(level == 0 or level == numRow-1)转向。
*/

#include <stack>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
    public: 
        string convert(string s, int numRows) 
        {
            if(numRows == 1) return s;
            string res;
            // 定义一个方向
            int dir = 1;
            // 定义一个numrows行数组
            vector<string> vec(numRows, "");
            // 定义一个行号
            int row = 0;
            for(int i = 0;i < s.size();i++)
            {
                vec[row].push_back(s[i]);
                row += dir;
                // 如果到达了最后一行，就向上移动
                if(row == numRows - 1) dir = -1;
                // 如果在第一行，就向下移动
                if(row == 0) dir = 1;
            }
            for(int i = 0; i < vec.size();i++) res.append(vec[i]);
            return res;
        }  
};

int main()
{
    return 0;
}

