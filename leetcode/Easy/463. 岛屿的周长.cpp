/**
给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。
网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，
但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。
格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
示例 :
输入:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

输出: 16

*/

/**
解题思路：
暴力破解
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
  public:
    int islandPerimeter(vector<vector<int> > &grid)
    {
        int res = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                {
                    // 默认每个陆地有四个边
                    res += 4;
                    // 如果grid[i+1][j]不超出数组并且也等于1（岛）则边减2
                    if (i + 1 < row && grid[i + 1][j] == 1)
                    {
                        res = res - 2;
                    }
                    // 如果grid[i][j+1]不超出数组并且也等于1（岛）则边减2
                    if (j + 1 < col && grid[i][j + 1] == 1)
                    {
                        res = res - 2;
                    }
                }
            }
        }
        return res;
    }
};

// 另一种暴力搜索的解法
class Solution_
{
  public:
    int search_around(int **grid, int row, int col, int i, int j)
    {
        int same = 0, x, y;
        if (i - 1 >= 0 && grid[i - 1][j] == 1)
            same++; //左
        if (i + 1 < row && grid[i + 1][j] == 1)
            same++; //右
        if (j - 1 >= 0 && grid[i][j - 1] == 1)
            same++; //上
        if (j + 1 < col && grid[i][j + 1] == 1)
            same++; //下

        return same;
    }

    int islandPerimeter(int **grid, int gridRowSize, int gridColSize)
    {
        // 对于一个 1 周围每多一个 1 周长就加 4-i
        // 遍历所有节点  及其 周围的 4 个元素

        int i, j, count = 0;
        for (i = 0; i < gridRowSize; i++)
        { //遍历每一排
            for (j = 0; j < gridColSize; j++)
            { // 遍历每一列
                if (grid[i][j] == 1)
                {
                    switch (search_around(grid, gridRowSize, gridColSize, i, j))
                    {
                    case 1:
                        count += 3;
                        break;
                    case 2:
                        count += 2;
                        break;
                    case 3:
                        count += 1;
                        break;
                    case 4:
                        count += 0;
                        break;
                    default:
                        return 4;
                    }
                }
            }
        }

        return count;
    }
};
