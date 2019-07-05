/**
 * 并查集练习算法用来检测是否存在环
 */

#include <bits/stdc++.h>


using namespace std;


#define max_vertices 6


// 寻找父节点
int find_parent(int x,int *parent)
{
    int x_parent = x;
    while(parent[x_parent] != x_parent)
    {
        x_parent = parent[x_parent];
    }    
    return x_parent;
}

// 合并节点
// 返回1，说明合并成功，返回0，合并失败，也就是存在环
int union_parent(int x,int y,int *parent)
{
    int x_parent = find_parent(x,parent);
    int y_parent = find_parent(y,parent);
    if(x_parent == y_parent)
    {
        return 0;
    }
    else 
    {
        parent[x_parent] = y_parent;
        return 1;
    }
}


// 初始化，每个节点的父节点是其本身
void init(int *parent,int size)
{
    for(int i = 0;i < size;i++)
        parent[i] = i;
}

int main()
{

    int parent[max_vertices] = {0};

    init(parent,max_vertices);

    int edges[5][2]=
    {
        {0,1},
        {1,2},
        {1,3},
        // {2,4},
        {3,4},
        {2,5}
    };

    for(int i  = 0;i < 5;i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        if(union_parent(x,y,parent) == 0)
        {
            cout << "Cycle." << endl;
            exit(1);
        }
    }
    cout << "No Cycle." << endl;

    return 0;
}