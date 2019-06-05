/**
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。

示例 1：
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶

示例 2：
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
*/

/**
解题思路：
剑指offer变体，斐波那契数列
1.解题思路：
使用一个数组来保存当前楼层的方式
2.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int f = 1;
        int g = 1;
        int temp = 0;
        // if(n == 1) return f;
        // if(n == 2) return g;
        for(int i = 1;i < n;i++)
        {
            // 注意这里的转换代码
            // 保留上一个f值
            temp = f;
            // 更新f值
            f = f + g;
            // 将上一个f值赋值给前一个g
            g = temp;
        }
        return f;    
    }
    int climbStairs_(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        vector<int> vec(n + 1,-1);
        vec[0] = 0;
        vec[1] = 1;
        vec[2] = 2;
        for(int i = 3;i <= n;i++)
        {
            vec[i] = vec[i - 1] + vec[i - 2];
        }
        return vec[n];    
    }
};

int main()
{
    Solution s;
    int n ;
    cin >> n;
    int t = s.climbStairs_(n);
    cout << t << endl;
    return 0;
}
