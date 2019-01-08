/**
给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，
其中 i 和 j 之间的距离和 i 和 k 之间的距离相等（需要考虑元组的顺序）。
找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。
示例:
输入:
[[0,0],[1,0],[2,0]]
输出:
2
解释:
两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
*/

/**
解题思路：
暴力求解
*/
#include <map>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


class Solution 
{
    public:
        int numberOfBoomerangs(vector<pair<int, int> >& points) 
        {
            // 定义回旋镖的个数
            int ans = 0,size = points.size();
            // 定义每个点的距离矩阵
            vector<vector<int> > dist(size, vector<int> (size,0));
            // 定义相同距离的节点的哈希表
            unordered_map<int, int> ijk;
            // 二重for循环暴力计算
            for(int i = 0;i < size;i++)
            {
                for(int j = i + 1; j < size;j++)
                {
                    int dx = points[i].first - points[j].first;
                    int dy = points[i].second - points[j].second;
                    // 矩阵具有对称性
                    dist[i][j] = dist[j][i] = dx * dx + dy * dy;
                }
                for(int k = 0; k < size;k++)
                {
                    ++ijk[dist[i][k]];
                }
                for(auto c : ijk)
                {
                    // 从n个点中选取两个点的方案数量为(n * n - 1)
                    // second是value，first是key
                    ans += c.second * (c.second - 1);
                }
                ijk.clear();
            }

            return ans;
        }
};

int main(int argc, char const *argv[])
{
    return 0;
}
