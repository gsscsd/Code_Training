/**
给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:
输入: 5
输出:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

/**
解题思路：
暴力for循环
两层for循环
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
    public: 
        // 思路比较简单和冗余
        vector<vector<int> > generate(int numRows) 
        {
            vector<vector<int> > result;
            if(numRows < 1) return result;
            vector<int > temp;
            temp.push_back(1);
            result.push_back(temp);
            // 从第二行开始进行迭代
            for(int i = 1;i < numRows;i++)
            {   
                temp.clear();
                temp.push_back(1);
                // 对于每一行的数，进行计算
                for(int j = 0; j < i - 1;j++)
                {
                    // 测试语句
                    // cout << "j is " << j << endl;
                    temp.push_back(result[i - 1][j] + result[i - 1][j + 1]);
                }
                temp.push_back(1);
                result.push_back(temp);
            } 
            return result;
        }
        // leetcode的高票答案
        vector<vector<int> > generate_(int numRows) {
            // 预定义变量
            vector<vector<int> > vec;
            // 可能的边界判断
            if(numRows <= 0)
                return vec;
            for(int i = 0;i < numRows ; i++) {
                // 还有这种写法？第一次见，C++的写法也还是有很多的技巧的。
                // 插入一个vector，初始所有的元素都为1.
                vec.push_back(vector<int> (i+1,1));
                for(int j = 1 ;j < i ; j++) {
                    // 迭代的计算，动态规划，不过，是不是有个问题，最后一个元素为1，是否没有检测
                    vec[i][j] = vec[i-1][j-1]+vec[i-1][j];
                }
            }
            return vec;
        }
};


int main()
{
    vector<vector<int> > v;
    Solution s;
    v = s.generate_(5);
    int i_len = v.size();
    for(int i = 0 ;i < i_len;i++)
    {
        for(auto v1:v[i])
        {
            cout << v1 << " ";
        }
        cout << endl;
    }

    return 0;
}



