/**
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true

示例 2:
输入: "race a car"
输出: false 
*/

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;

class Solution 
{
    public :
        bool isPalindrome(string s) 
        {
            int s_len = s.length();
            string s_t = "";
            if(s_len <= 1) return true;
            int i = 0;
            while(i < s_len)
            {
                if((s[i] >='0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                {
                    s_t += s[i];
                }
                i++;
            }
            int s_t_len = s_t.length();
            transform(s_t.begin(),s_t.end(),s_t.begin(),::tolower); 
            cout << "s temp is " << s_t << endl;
            for(int j = 0; j < s_t_len / 2;j++)
            {
                if(s_t[j] != s_t[s_t_len - 1 - j]) return false;
            }
            return true;
        }

};
// leetcode 的高票双指针解法
class Solution_ {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i < j){
            while(i < j && !isAlphaNum(s[i]))
                i++;
            while(i < j && !isAlphaNum(s[j]))
                j--;
            if(tolower(s[i]) == tolower(s[j])){
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
private:
    bool isAlphaNum(char c){
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
};

int main()
{
    Solution s;
    string st = "A man, a plan, a canal: Panama";
    bool b = s.isPalindrome(st);
    cout << b << endl;
    return 0;
}
