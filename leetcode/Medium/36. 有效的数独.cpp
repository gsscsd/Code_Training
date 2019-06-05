/**
判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
*/
/**
解题思路：
模拟运行，空间换时间
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // 检验行的有效性
        bool row[9][9] = {false};
        // 检验列的有效性
        bool col[9][9] = {false};
        // 检验子数组的有效性
        bool sub[9][9] = {false};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1;
                    if (row[i][num] || col[j][num] || sub[i / 3 * 3 + j / 3][num])
                    {
                        return false;
                    }
                    else
                    {
                        row[i][num] = true;
                        col[j][num] = true;
                        sub[i / 3 * 3 + j / 3][num] = true;
                    }
                }
            }
        }
        return true;
    }
};