/**
给定两个二进制字符串，返回他们的和（用二进制表示）。
输入为非空字符串且只包含数字 1 和 0。

示例 1:
输入: a = "11", b = "1"
输出: "100"

示例 2:
输入: a = "1010", b = "1011"
输出: "10101"
*/

/**
解题思路：
1.遍历位操作
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
// 自己想的像屎一样的代码，一大坨的很冗余的代码，应该能够优化
// 108ms的时间复杂度，果然很差劲
    string addBinary(string a, string b) {
        string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        bool flag = false;
        int temp = 0;
        while(i >= 0 && j >= 0)
        {
            // 判断是否进位
            if(flag)
            // 如果进位的话，还要加1
                temp  = a[i] - '0' + b[j] - '0' + 1;
                // 否则不用加1
            else temp = a[i] - '0' + b[j] - '0';
            // 如果加完之后，大于2 ，说明进位了
            if(temp >= 2)
            {
                // 进位之后，
                temp = temp - 2;
                // flag为true
                flag = true;
            }
            else
            {
                flag = false;
            }
            result = to_string(temp) + result;
            i--,j--;
        }
        while(i >= 0)
        {
            if(flag) temp = a[i] - '0' + 1;
            else temp = a[i] - '0';
            cout << "ai " << a[i] << " temp is " << temp << endl;
            if(temp >= 2)
            {
                temp = temp - 2;
                flag = true;
            }
            else flag = false;
            result = to_string(temp) + result;
            i--;
        }
        while(j >= 0)
        {
            if(flag) temp = b[j] - '0' + 1;
            else temp = b[j] - '0';
            if(temp >= 2)
            {
                temp = temp - 2;
                flag = true;
            }
            else flag = false;
            result = to_string(temp) + result;
            j--;
        }
        if(flag) result = "1" + result;
        return result;
    }

    //leetcode大佬的代码 16ms
    string addBinary_(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1;
        string ret = "";
        int flag = 0;
        while(i >= 0 || j >= 0){
            // 对，这里的代码，很眼熟，与之前的中等难度的两数相加的解法很相似
            int at = (i >= 0) ? a[i] - '0' : 0;
            int bt = (j >= 0) ? b[j] - '0' : 0;
            int temp = at + bt + flag;
            // 这里的carry用来做标记，判断是否大于2
            // 这里除以2，如果大于2就会为1，不大于2就会为0
            flag = temp / 2;
            // 在这里，每次加到最前面
            ret = to_string(temp % 2) + ret;
            --i,--j;
        }
        // 这里，如果标记为1，那么头部加1
        if (flag != 0){
            ret = "1" + ret;
        }
        return ret; 
    }
};

int main()
{
    string a = "11",b = "1";
    Solution s;
    string t = s.addBinary_(a,b);
    cout << t << endl;
    return 0;
}






