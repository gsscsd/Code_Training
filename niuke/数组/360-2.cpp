/**
360 第二题，范围内的进制转换
参数q，是指q组
参数k是进制，参数l，r是范围
题目没有读懂
结果是29%
*/

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


int main()
{
    int q;
    cin>>q;
    vector<int> res;
    int k,l,r;
    while(q--)
    {
        cin>>k>>l>>r;
        int i = 0;
        int t = 0;
        // 这里的算法思想是啥？？
        while(t <= r)
        {
            t += (k-1) * pow(k,i++);
        }
        t -= (k-1) * pow(k,i-1);
        // 将这个数存到数组里
        res.push_back(t);
    }
    // 打印
    for(auto it:res)
    {
        cout<<it<<endl;
    }
    return 0;
}

