/**
给定一个正整数，返回它在 Excel 表中相对应的列名称。

例如，
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...

示例 1:
输入: 1
输出: "A"

示例 2:
输入: 28
输出: "AB"

示例 3:
输入: 701
输出: "ZY"
*/
/**
解题思路：
递归或者是迭代
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
    public:
        string convertToTitle(int n) 
        {
            // 定义一个字符串
            string re = "";
            while(n != 0){
                int cur = n;
                char temp;
                // 这里不太清楚呢
                // 如果余26==0，那么说明是最后一个元素，需要减1
                if(cur % 26 != 0)
                    temp = 'A' + cur % 26 - 1;
                else{
                    temp = 'Z';
                    n--;
                }
                re = temp + re;
                n/=26;
            }
            return re;
        }
        // 定义一个字典去映射
        string convertToTitle_(int n)
        {
            vector<char> vec(27,'Z');
            for(int i = 1;i < 27;i++)
            {
                vec[i] = 'A' + i - 1;
            }
            string re = "";
            while(n != 0)
            {
                re = vec[n % 26] + re;
                // 为啥进行减1呢？
                // n = (n - 1) / 26;
                // 另一种控制的方法
                if(n % 26 == 0) n = n - 26;
                else n = n - n % 26;
                n /= 26;
            }
            return re;
        }
        string convertToTitle_1(int n) {
        return n == 0 ? "" : convertToTitle(n / 26) + (char)(--n % 26 + 'A');
    }
};
// 递归的解决方法
class Solution_
{
    public:    
        void appendChar(int n, string& result) {
            // 递归的边界
            if(n == 0)
                return;
            // 递归体
            result = (char)((--n) % 26 + 'A') + result;
            appendChar( n / 26, result);
        }
        
        string convertToTitle(int n) {
            string result;
            appendChar(n, result);
            return result;
        }
};

int main()
{
    Solution s;
    int n;
    cin >> n;
    string re = s.convertToTitle_(n);
    cout << re  << endl;
}