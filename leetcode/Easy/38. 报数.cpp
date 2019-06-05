/**
报数序列是指一个整照其中的整数的顺序进数序列，按行报数，得到下一个数。其前五项如下：
1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
注意：整数顺序将表示为一个字符串。
*/


/**
解题思路：
设定两个string类型，一个用来返回，一个用来缓存
*/


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        // 先设定一个result
        string result = "1";
        // temp做中间的缓存
        string temp = "";
        if(n == 1) return result;
        // 两层for循环
        for(int i = 0;i < n - 1;i++)
        {
            int count = 1;
            // 每次对result里面的数进行计算
            for(int j = 0; j < result.size();j++)
            {
                // 如果当前的数和下一个数相同，那么就count就加一
                if(result[j] == result[j + 1])
                {
                    count ++;
                }
                // 如果不相等，那么就将频率和字符加在一起
                else
                {
                    temp += to_string(count);
                    temp += result[j];
                    count = 1;
                }
            }
            // 把temp赋值给result
            result = temp;
            // temp为空
            temp = "";
        }
        return result;
    }
    string countAndSay_(int n) {
        if( n == 1) return "1";
        string prev = countAndSay(n - 1), res = "";
        for(char c : prev)  
        {
            if(res == "" || c != res.back())
            {
                res += "1";
                res += c;
            }
            else
                res[res.size() - 2]++;
        }
        return res;
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