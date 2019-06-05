/**
题目描述：
大富翁游戏中停留在敌方设施时需要交通行费，现在我们提供一种简化的场景，假设你每轮只能前进一步或两步，给定在前方一段道路上每一步停留所需支付的通行费，求通过此区域所需通行费可能的最小值。

输入
第一行给定前方道路长度，一个整数N (1<=N<=100)

接下来N行是停留费用，整数c1，c2，...，cN，（0<<=ci<=1000)

输出
一个整数，表示停留费用最小值
*/


/**
解题思路：
1.动态规划 55%
*/


#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;



int main()
{
        int n = 0;
        cin >> n;
        vector<int> vec;
        for(int i = 0; i < n;i++)
        {
                int temp ;
                cin >> temp;
                vec.push_back(temp);
        }
        if(n == 1) return vec[0];
        if(n == 2) return min(vec[0],vec[1]);
        // int min_num = 0;
        // int s0 = vec[0],s1 = vec[1];
        vector<int> temp ;
        temp.push_back(vec[0]);
        temp.push_back(vec[1]);
        for(int i = 2; i < n;i++)
        {
                int min_num = min(vec[i] + temp[i - 1],vec[i] + temp[i - 2]);
                temp.push_back(min_num);
        }
        cout << temp[n - 1] << endl;  

        return 0;
}