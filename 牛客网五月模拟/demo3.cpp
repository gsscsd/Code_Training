/**
BFS
*/



#include <iostream>
#include <bits/stdc++.h>


using namespace std;


int n = 0;

// 定义方向
int direct[2][2] = {{0,1},{0,-1},{1,0},{-1,0}};

// 检查是否能通过
bool check(int i,int j,int n,vector<vector<int> > &mi,vector<vector<bool> > &flag)
{
    // 在边界范围内，同时，这个位置能够走
    if(i > 0 && i <= n && j > 0 && j <= n && (mi[i][j] == '.' || mi[i][j] == '@') && !flag[i][j])
        return true;
    return false;
}


int bfs(vector<vector<int> > &mi,vector<vector<bool> > &flag,int i,int j)
{
    int count = 0;
    if(mi[i][j] == '*') return count;
    if(check(i,j,n,mi,flag))
    {
        flag[i][j] = true;
        count = 1 + bfs(mi,flag,i + 1,j)
                + bfs(mi,flag,i - 1,j)
                + bfs(mi,flag,i,j - 1)
                + bfs(mi,flag,i,j + 1);
    }
    return count;
}


int main()
{
    cin >> n;
    // 定义数组
    vector<vector<int> > mi(n + 1,vector<int>(n + 1,0));
    vector<vector<bool> > flag(n,vector<bool>(n + 1,false));
    char a = '';
    // 读入数据
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0;j < n ;j++)
        {
            cin >> a;
            mi[i][j] = a;
        }
    }
    // BFS搜索路径
    int res = bfs(mi,flag,0,0);
    cout << res << endl;



    return 0;
}