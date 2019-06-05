/**
给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:
输入: 3
输出: [1,3,3,1]
// 难点在于如何优化到线性空间复杂度
你可以优化你的算法到 O(k) 空间复杂度吗？
*/


/**
解题思路：
迭代递归？ 
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution 
{
    public : 
         vector<int> getRow(int rowIndex) {
            vector<int> vec;
            vec.push_back(1);
            if(rowIndex <= 0) return vec;
            // 注意这里的边界条件
            for(int i = 0 ; i <= rowIndex;i++)
            {
                vector<int> temp(i + 1,1);
                for(int j = 1;j < i ;j++)
                {
                    temp[j] = vec[ j ] + vec[ j - 1];
                }
                vec = temp;
                temp.clear();
            }
            return vec;
        }   
        // leetcode高效答案
        // 没有看懂答案的原理是干嘛
        vector<int> getRow_(int rowIndex) {
            vector<int> res(rowIndex+1,0);
            res[0] = 1;
            for(int i = 1;i <= rowIndex;i++){
                for(int j = i;j > 0;j--){
                    res[j] += res[j-1];
                }
            }
        return res;
    }
};


int main()
{
    vector<int> v;
    Solution s;
    v = s.getRow(3);
    for(auto a : v)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}



