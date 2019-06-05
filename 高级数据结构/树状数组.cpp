/**
树状数组：
用途： 树状数组是一个查询和修改复杂度都为log(n)的数据结构。主要用于数组的单点修改&&区间求和.
参考链接：https://blog.csdn.net/bestsort/article/details/80796531
https://www.bilibili.com/video/av18373508/?p=2
基本概念：C数组，大小为1-N
C[i]=A[i-2^k+1]+A[i-2^k+2]+......A[i]; （k为i的二进制中从最低位到高位连续零的长度）例如i=8时，k=3;
核心代码操作：
lowbit用于查询节点之间的联系
int lowbit(x){return x&(-x);}

插入数据到C数组中
void update(int x,int y,int n){
    for(int i=x;i<=n;i+=lowbit(i))    //x为更新的位置,y为更新后的数,n为数组最大值
        c[i] += y;
}

计算区间和，计算区间1-X之间的和
int getsum(int x){
    int ans = 0;
    for(int i=x;i;i-=lowbit(i))
        ans += c[i];
    return ans;
}
*/

/**
例题1 ：
例题：POJ - 2352    （http://poj.org/problem?id=2352）
题目大意：输入n个星星坐标，坐标按y递增顺序输入，y相同按x递增顺序输入。定义一个星星的级别是横纵坐标都不超过自己的星星个数（不包括自己），问级别为0~n-1的星星分别有多少个。
题目思路：我们可以发现，当前输入这个星星，跟后面的星星没有关系，因为后面输入的星星横纵坐标肯定会有超过当前星星的。所以只要把当前输入的x之前的横坐标加起来就可以了。
树状数组非常非常的符合这个特性。要注意的一点是树状数组下标从1开始算，所以把题目输入的横坐标全部右移了一位。
#include <iostream>
using namespace std;
int tree[32001],level[32001];
int lowbit(int x){return x&(-x);}
int read(int k)        
{
    int sum=0;
    while(k)
    {
        sum += tree[k];
        k -= lowbit(k);
    }
    return sum;
}
void add(int k)
{
    while(k<=32001)
    {
        tree[k]++;
        k += lowbit(k);
    }
}
int main()
{
    int n,i,x,y;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        level[read(x+1)]++;        //全部x右移一位
        add(x+1);
    }
    for(i=0;i<n;i++)
        cout<<level[i]<<endl;
}
 */