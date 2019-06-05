/**
貌似使用图的广度遍历
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 2001;
const int maxq = 2001;
const int maxa = 1001;

//邻接矩阵
char g[maxn][maxn] = {'*'};//graph
int node[maxn];
int n,m;

//在一般情况下，u和v分别表示边的起点和终点，w表示权值

void adde(int u,int v,char w)
{
    g[u][v]=w;//有向
}


int solve(char edge[][maxn],int start)
{

    return 0;
}


int main()
{
    int n,q;
    cin >> n >> q;
    for(int i = 1;i < n + 1;i++)
    {
        cin >> node[i];
    }

    for(int i = 1;i < n;i++)
    {
        int x,y;
        char ch;
        cin >> x >> y >> ch;
        g[x][y] = ch;
    }
    for(int i = 0;i < q;i++)
    {
        int start;
        cin >> start;
        int maxNum = 0;
        maxNum = solve(g,start);
        cout << maxNum;
    }
    return 0;
}