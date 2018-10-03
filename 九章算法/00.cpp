/**
回文串是指aba、abba、cccbccc、aaaa这种左右对称的字符串。
输入一个字符串Str，输出Str里最长回文子串的长度。
*/

/**
动态规划
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int dpAlgorithm(string &str) 
{    
        int length = str.size();   
        string s0(str);
        string s1(str); 
        vector<vector<int> > dp(length, vector<int>(length, 0));    
        for (int i = length - 1; i >= 0; i--) 
        {        
                dp[i][i] = 1;        
                for (int j = i + 1; j < length; ++j) 
                {            
                        if (str[i] == str[j]) 
                        {                
                                dp[i][j] = dp[i+1][j-1] + 2;            
                        } 
                        else 
                        {                
                                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);            
                        }        
                }    
        }

} 


int main(int argc, char const *argv[])
{
        string str = "";
        cin >> str;
        int longest = dpAlgorithm(str);
        cout << longest << endl;
        return 0;
}
