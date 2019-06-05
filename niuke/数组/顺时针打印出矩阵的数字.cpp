/**
题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
解题思路
    思想，用左上和右下的坐标定位出一次要旋转打印的数据，一次旋转打印结束后，往对角分别前进和后退一个单位。
    提交代码时，主要的问题出在没有控制好后两个for循环，需要加入条件判断，防止出现单行或者单列的情况。
 */

class Solution {
public:
    // 这个代码是抄的
    vector<int> printMatrix(vector<vector<int> > matrix) {

        int row = matrix.size();
        int col = matrix[0].size();
        vector<int > res;
        if(row == 0 || col == 0) return res;

        // 定义四个关键变量，表示左上和右下的打印范围
        int left = 0,top = 0,right = col - 1,bottom = row - 1;
        while(left <= right && top <= bottom )
        {
            // 好好思索这个代码，以下是打印行的代码
            for(int i = left; i <= right; i++) res.push_back(matrix[top][i]);
            // 以下是打印列的代码
            for(int i = top + 1;i <= bottom; i++) res.push_back(matrix[i][right]);
            // 以下right to left
            // 注意以下for循环以及if的判断边界条件
            if(top != bottom)
            {
                for(int i = right - 1;i >= left;i--) res.push_back(matrix[bottom][i]);
            }
            if(right != left)
            {
                for(int i = bottom - 1;i > top;i--) res.push_back(matrix[i][left]);
            }
            // 循环一圈以后
            left++,top++,right--,bottom--;
        }
    }
    return res;
};

int main()
{

}