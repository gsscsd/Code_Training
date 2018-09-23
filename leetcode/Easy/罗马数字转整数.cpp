/**
罗马数字转整数
罗马数字包含以下七种字符：I， V， X， L，C，D 和 M。
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
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
*/

/**
解题思路：
遍历查找 
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
    int romanToInt(string s) {

        // 设定字典的方法应该比较好
        map<char,int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        // for循环遍历，根据上面出现的情况来进行判定计算
        int len = s.length();
        // 先计算最后一个数
        int result = mp[s[len - 1]];

        // 然后从后面向前面去遍历
        for(int i = len - 2;i >= 0;--i)
        {
            // 未优化 80ms
            // cout << s[i] << endl;
            // 代码太啰嗦了，虽然也可以运行
            // if(s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X'))
            //     result -= mp[s[i]];
            // else if(s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C'))
            //     result -= mp[s[i]];
            // else if(s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))
            //     result -= mp[s[i]];
            // else result += mp[s[i]];
            // 此处优化一下，根据题目中 "罗马数字中小的数字在大的数字的右边" 
            // 如果，前面的字符对应的数比当前的数要大，说明需要加上当前这个数。
            // 大神的代码 大约是
            if(mp[s[i]] >= mp[s[i+1]])
                result += mp[s[i]];
            // 如果前面字符对应的数比当前的数要小，说明需要减去这个数。
            else
                result -= mp[s[i]];
        } 
        return result;
    }
};

int main()
{
    string str = "MCMXCIV";
    Solution s;

    int temp = s.romanToInt(str);
    cout << temp << endl;
    return 0;
}
