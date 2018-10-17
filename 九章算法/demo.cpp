/***
N*M矩阵，机器人从（0，0）走到终点，每次可以上下左右移动，求最短路径
第一行输入N,M
接下来为矩阵
例如：
3 3
0 1 2
2 3 -1 
1 3 1
输出7
*/
/**
解题思路：
1.回溯
2.搜索
3.动态规划
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

#define maxn 4

int mazeArr[maxn][maxn]; //表示的是0 1矩阵
int stepArr[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; //表示上下左右4个方向
int visit[maxn][maxn]; //表示该点是否被访问过，防止回溯，回溯很耗时。

struct Node
{
    int x;
    int y;
    int step;
    Node(int x1, int y1, int step1) : x(x1), y(y1), step(step1) {}
};

int BFS(int n)
{
    Node node(0, 0, 0);
    queue <Node> q;
    while (!q.empty())
        q.pop();
    q.push(node);
    while (!q.empty())
    {
        node = q.front();
        q.pop();
        if (node.x == n - 1 && node.y == n - 1)
        {
            return node.step;
        }
        visit[node.x][node.y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int x = node.x + stepArr[i][0];
            int y = node.y + stepArr[i][1];
            if (x >= 0 && y >= 0 && x < n && y < n && visit[x][y] == 0 && mazeArr[x][y] != 0)
            {
                visit[x][y] = 1;
                Node next(x, y, node.step + 1);
                q.push(next);
            }
        }
    }
    return -1;
}
