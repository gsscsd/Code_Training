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

using namespace std;


class Solution 
{
    public :
        int min_path(vector<vector<int> > &num,int rows,int cols)
        {
            vector<vector<int> > dp(rows,vector<int>(cols));
            for(int i = 0;i < rows;i++)
            {
                for(int j = 0;j < cols;j++)
                {
                    if(j == 0 && i == 0) dp[i][j] = num[i][j];
                    if(i == 0)
                    {
                    }
                }
            }

        }
};


int main()
{
    int m,n;
    cin >> n >> m;
    vector<vector<int> > num(n,vector<int>(m));  
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m ;j++)
        {
            int temp = 0;
            cin >> temp;
            num[i][j] = temp;
        }
    }
    Solution s;

    int min_p = s.min_path(num,n,m);
    cout << min_p;
    return 0;
}