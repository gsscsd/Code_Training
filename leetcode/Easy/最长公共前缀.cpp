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
暴力for循环
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
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
        cout << re << endl;
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
