/**
题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
则打印出这三个数字能排成的最小数字为321323。
 */

/**
解题思路：
类似于2017年真题测试的数串处理
 */
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// 预定义一个函数


class Solution {
public:
    //函数需要定义成static类型么？？
    static bool cmp(string a,string b){
        //    这里主要交换的位置
            return (a+b) < (b+a);
        }
        // ps说明一下，代码空间效率比较低O(n)；
    string PrintMinNumber(vector<int> numbers) {
        vector<string> temp;
        for(int i = 0;i < numbers.size();i++)
        {
            
            temp.push_back(to_string(numbers[i]));   
        }
        sort(temp.begin(),temp.end(),cmp);
        
        string result = "";
        for(auto t:temp)
        {
            result += t;
        }
        cout << result << endl;
        return result;   
    }
    // 重新写代码，优化空间复杂度
    // 首先重新定义sort的比较函数
    static bool campare(int a,int b)
    {
        string A = "";
        string B = "";
        A += to_string(a),A += to_string(b);
        B += to_string(b),B += to_string(a);
        return A < B;

    }
    string PrintMinNumber_(vector<int> numbers)
    {
        // 直接去排序，数据类型的转换放在sort函数里面
        sort(numbers.begin(),numbers.end(),campare);
        string result = "";
        for(auto n : numbers)
        {
            result += to_string(n);
        }
        return result;
    }
};

int main()
{
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(1);
    vec.push_back(4);
    vec.push_back(2);
    Solution s;
    s.PrintMinNumber(vec);

}