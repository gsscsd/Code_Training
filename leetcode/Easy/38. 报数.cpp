/**
报数序列是指一个整照其中的整数的顺序进数序列，按行报数，得到下一个数。其前五项如下：
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
注意：整数顺序将表示为一个字符串。
*/


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        string temp = "";
        if(n == 1) return result;
        for(int i = 0;i < n - 1;i++)
        {
            int count = 1;
            for(int j = 0; j < result.size();j++)
            {
                if(result[j] == result[j + 1])
                {
                    count ++;
                }
                else
                {
                    temp += to_string(count);
                    temp += result[j];
                    count = 1;
                }
            }
            result = temp;
            temp = "";
        }
        return result;
    }
};

int main()
{
    int m = 0;
    cin >> m;
    Solution s;
    string str = s.countAndSay(m);
    cout << str << endl;
    return 0;
}