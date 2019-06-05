/**

罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

示例 1:

输入: 3
输出: "III"
示例 2:

输入: 4
输出: "IV"
示例 3:

输入: 9
输出: "IX"
示例 4:

输入: 58
输出: "LVIII"
解释: L = 50, V = 5, III = 3.
示例 5:

输入: 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.
*/

/**
解题思路：
剑指offer的题目
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution 
{
    public:
        string intToRoman(int num) {
            string res = "";
            // 设计一个映射数组
            map<int,char> mp;
            mp[1] = 'I';
            mp[5] = 'V';
            mp[10] = 'X';
            mp[50] = 'L';
            mp[100] = 'C';
            mp[500] = 'D';
            mp[1000] = 'M';
            int temp = 0;
            int i = 1;
            while(num > 0)
            {
                temp = num % 10;
                num /= 10;
                if(temp == 4 || temp == 9)
                {
                    res =  mp[(temp + 1) * i] + res;
                    res =  mp[i] + res;
                }
                else if (temp == 5 || temp == 1)
                {
                    res = mp[temp * i] + res;
                }
                else if(temp > 5)
                {
                    temp -= 5;
                    string st(temp,mp[i]);
                    res = st + res;
                    res = mp[5 * i] + res;
                }
                else 
                {
                    string st(temp,mp[i]);
                    res = st + res;
                }
                i *= 10;
            }
            return res;
        }
};

// 双数组来映射然后处理
class Solution_0 {
public:
    string intToRoman(int num) {
        string res = "";
        char roman[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int value[] = {1000, 500, 100, 50, 10, 5, 1};
        
        for (int n = 0; n < 7; n += 2) {
            int x = num / value[n];
            if (x < 4) {
                for (int i = 1; i <= x; ++i) res += roman[n];
            } else if (x == 4) res = res + roman[n] + roman[n - 1];
            else if (x > 4 && x < 9) {
                res += roman[n - 1];
                for (int i = 6; i <= x; ++i) res += roman[n];
            }
            else if (x == 9) res = res + roman[n] + roman[n - 2];
            num %= value[n];            
        }
        return res;
    }
};

// 将所有的字符做了一个映射
// 这种解法可以好好的思考一下
class Solution_1 {
public:
    string intToRoman(int num) {
        string res = "";
        vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> str{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < val.size(); ++i) {
            while (num >= val[i]) {
                num -= val[i];
                res += str[i];
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}

