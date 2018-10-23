/**
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
你能不将整数转为字符串来解决这个问题吗？
*/

/**
解题思路
*/

#include <iostream>
#include <vector>
#include <string>


using namespace std;


class Solution {
public:
    // 采用反转整数的方式，100ms
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int temp = x;
        int reverse = 0;
        while(temp != 0)
        {
            reverse = reverse * 10 + (temp % 10);
            temp /= 10;
        }
        return !(reverse - x);    
    }
    // 采用字符串的方式 204ms
    bool isPalindrome_(int x)
    {
        string s = to_string(x);
        int len = s.length();
        for(int i = 0;i < len;i++)
        {
            if(s[i] != s[len - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};


int main()
{
    return 0;
}

