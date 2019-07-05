/**
动态规划
不一定是动态规划，还有可能是贪心呢
*/

#include <iostream>
#include <bits\stdc++.h>

using namespace std;


// sort的第三个参数，同时需要对二维数组排序
static bool comp(vector<int> &a,vector<int> &b)
{
    // 应该是这个样子吧
    return a[1] > b[1];
}

// 贪心算法
int getNum(vector<vector<int>> &mm,int nums)
{
    // 首先来排序，按照y从小到大或者从大到小。
    sort(mm.begin(),mm.end(),comp);
    int min_money = 0xffffffff;
    int mm_size = mm.size();
    for(int i = 0 ;i < mm_size / 2;i++)
    {
        int num = mm[i][1] + mm[mm_size - 1 - i][1];
        if()

    }
}


int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    n += 1;
    int base_money = n * k;
    vector<vector<int>> mm(m + 1,vector<int>(2,0))
    for(int i = 0; i <= m;i ++)
    {
        cin >> mm[i][0] >> mm[i][1];
    }

    // 调用函数，来动态规划

    
    return 0;
}

