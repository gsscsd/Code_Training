/**
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
*/

/**
解题思路：
1.暴力for循环
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 这个函数是用来做比较的，是sort函数的第三个参数，根据字符串长度来排序
    static int cmp(string i,string j)
    {
        return i.length() < j.length();
    }

    string longestCommonPrefix_(vector<string>& strs) {

        if(strs.size() < 1 ) return "";
        // 排序，根据字符串的长度来排序
        sort(strs.begin(),strs.end(),cmp);
        // 找到最短的字符创
        string s0 = strs[0];
        // 预先定义一个result，用来保存前缀
        string result = "";

        // 开始遍历，根据最短的字符串的长度来遍历
        for(int i = 0;i < s0.length();++i)
        {
                // 设定一个标记，用来标记是否所有的字符串的的前缀都相等，默认是相等的
                bool is_valid = true;
                // for循环对剩下的其他字符串遍历，让它们与第一个字符串来比较
                for(int j = 1;j < strs.size();j++)
                {
                        // 我们默默的认为，理论上每个字符串的前缀都相等
                        // 此处，如果，第一个字符串的某个字符与其他字符串的字符不相等
                        if(s0[i] != strs[j][i])
                        {
                                // 这里是取！
                                // 对标记位取反，也就是说。找到了不相等的字符串
                                is_valid = !is_valid;
                                // 跳出循环
                                break;
                        }
                }
                // 如果标记为真，也就是前缀字符存在，那么就添加到result里
                if(is_valid) 
                {
                        // result是字符串，并且字符串的连接可以用加法实现
                        result += s0[i];
                }
                // 如果标记位为假，也跳出这一层循环
                else
                {
                        break;
                }
        }
        // 最后返回结果
        return result;

    }
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.size() < 1 ) return "";
        // 注意这里的re参数，循环赋值，最后找到最长的字符串
        string re = strs[0];
        // 双层for循环
        for(int i=1;i<strs.size();i++)
        {
            // 每次对比找到比较短的字符串的长度，然后根据这个长度来遍历
            int length = re.size()>strs[i].size()?strs[i].size():re.size();
            int j=0;
            // 第二层遍历
            for(;j < length;j ++)
                // 如果不想等，直接break
                if(re[j] != strs[i][j])
                    break;
            if( j == 0 )
                return "";
            // 截取部分字串
            re = re.substr(0,j); 
        }
        // cout << re << endl;
        return re;
    }
};

int main()
{
    Solution s;

    vector<string> vec;
    // vec.push_back("aca");
    // vec.push_back("cba");
    vec.push_back("flower");
    vec.push_back("flow");
    vec.push_back("flight");
    s.longestCommonPrefix(vec);

    return 0;
}
