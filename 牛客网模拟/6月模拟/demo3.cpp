/**
线性时间解决问题
类似于leetcode的查找子序列
深度搜索，但是不会
*/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e9 + 7;

int solve(int num)
{
    return pow(2,num - 1);
}


int main()
{
    int n;
    cin >> n;
    int num = solve(n);
    cout << num << endl;
    return 0;
}