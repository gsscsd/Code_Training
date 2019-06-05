/**
1.如果小明要买第i块木棍的话，他就必须把前i-1块木棍都买下来。

2.买了的木棍都必须用在圈地运动中。

那么请问小明最少买多少根木棍，才能使得木棍围成的图形是个面积大于0的多边形呢？
第一行一个数n，表示木棍个数。 第二行n个数，第i个数表示第i个木棍的长度ai 1<=n<=10000 1<=ai<=10000
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
#define INT_MIN 0x80000000;

int main(){
    int n;
    cin >> n;
    vector<int> vec;
    int res = 0;
    // 如果小于3，不能围成多边形，直接输出-1
    if(n<3)
    {
    cout << -1 << endl;
    }
    else
    {
        int t = 0;
        // int maxS = INT_MIN;
        for(int i = 0 ;i < n;++i)
        {
            cin >> t;
            vec.push_back(t);

            if(i >= 2)
            {
                // 排序
                sort(vec.begin(),vec.end());
                int sum = 0;
                // 把除最后的一个数的其他所有数加起来
                for(int j = 0;j < vec.size()-1 ; ++j)
                {
                    sum += vec[j];
                }
                // 计算前面的数之和，并与最后一个数做对比
                if(sum > vec[vec.size()-1])
                {
                    cout<< i + 1 <<endl;
                    break;
                }
            }
        }   
    }
    return 0;
}
