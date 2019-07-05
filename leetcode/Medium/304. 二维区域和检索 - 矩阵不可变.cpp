/**
给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。

示例:

给定 matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
说明:

你可以假设矩阵不可变。
会多次调用 sumRegion 方法。
你可以假设 row1 ≤ row2 且 col1 ≤ col2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-query-2d-immutable
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
解题思路：
二维线段树或树状数组
*/

#include <bits/stdc++.h>

using namespace std;

class NumMatrix
{
public:
    vector<vector<int>> sums;
    NumMatrix(vector<vector<int>> &matrix)
    {
        if (!matrix.size())
            return;
        sums = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < sums.size(); i++)
            for (int j = 1; j < sums[0].size(); j++)
                update(sums[i], j, matrix[i][j - 1]);
    }

    void update(vector<int> &sum, int x, int add)
    {
        for (int i = x; i < sum.size(); i += (i & -i))
            sum[i] += add;
    }
    int getSum(vector<int> &sum, int x)
    {
        int res = 0;
        for (; x > 0; x -= (x & -x))
            res += sum[x];
        return res;
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int res = 0;
        for (int i = row1; i <= row2; i++)
            res += getSum(sums[i], col2 + 1) - getSum(sums[i], col1);
        return res;
    }
};

class NumMatrix1
{
public:
    vector<vector<int>> matrix1;
    NumMatrix(vector<vector<int>> &matrix)
    {

        matrix1 = matrix;
        if (matrix.empty())
            return;
        int m = matrix1.size(), n = matrix1[0].size();

        for (int i = 0; i < m; ++i)
            for (int j = 1; j < n; ++j)
                matrix1[i][j] += matrix1[i][j - 1];
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {

        // return matrix1[1][4];
        int sum = 0;
        for (int i = row1; i <= row2; ++i)
        {
            sum += (matrix1[i][col2] - (col1 == 0 ? 0 : matrix1[i][col1 - 1]));
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */