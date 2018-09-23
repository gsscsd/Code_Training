/**
题目描述
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。HF作为牛客的资深元老,
自然也准备了一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,
他随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列唱首歌,
然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....
这样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1) 
*/

/**
解题思路：
1.约瑟夫环的变体问题 老老实实的递推计算
2.根据公式推导

如果只求最后一个报数胜利者的话，我们可以用数学归纳法解决该问题，为了讨论方便，先把问题稍微改变一下，并不影响原意：

 问题描述：n个人（编号0~(n-1))，从0开始报数，报到(m-1)的退出，剩下的人 继续从0开始报数。求胜利者的编号。

 我们知道第一个人(编号一定是m%n-1) 出列之后，剩下的n-1个人组成了一个新的约瑟夫环（以编号为k=m%n的人开始）:

        k  k+1  k+2  ... n-2, n-1, 0, 1, 2, ... k-2并且从k开始报0。

现在我们把他们的编号做一下转换：

k     --> 0

k+1   --> 1

k+2   --> 2

...

...

k-2   --> n-2

k-1   --> n-1

变换后就完完全全成为了(n-1)个人报数的子问题，假如我们知道这个子问题的解： 例如x是最终的胜利者，那么根据上面这个表把这个x变回去不刚好就是n个人情况的解吗？！！
ps映射公式为：x = (x' - k) % n
反向变换公式
x ->ｘ＇？(这正是从n-1时的结果反过来推n个人时的编号！)
0 -> k

1 -> k+1

2 -> k+2

...

...

n-2 -> k-2
变回去的公式很简单，相信大家都可以推出来：x' = ( x + k ) % n。
令f[i]表示i个人玩游戏报m退出最后胜利者的编号，最后的结果自然是f[n]。

递推公式

f[1]=0;

f[i]=(f[i-1] + m) % i;  (i>1)

有了这个公式，我们要做的就是从1-n顺序算出f[i]的数值，最后结果是f[n]。 因为实际生活中编号总是从1开始，我们输出f[n]+1。
*/



#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    // 以下是约瑟夫环的迭代解决方法。
    // 一定要好好看公式的推导
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1||m < 1) return -1;
        int p=0;
        for(int i=2;i<=n;i++)
        {
            p=(p+m)%i;
        }
            return p ;
    }
    // 以下是约瑟夫环的递归解决方法
     int LastRemaining_Solution_(int n, int m)
    {
        if(n == 0) return -1;
        if(n == 1) return 0;
        else
        {
            return (LastRemaining_Solution_(n - 1,m) + m) % n;
        }
    }
    // 网上的一个比较标准的代码
    int LastRemaining_Solution_0(int n,int m)
    {
        if(n < 1||m < 1) return -1;
        // // 分配一块flag数组，并初始化为0
        int *flag = new int[n]();
        // 设定两个指针，一个用来指向数组，一个用来指向是否m-1
        // 这里为啥是i=-1.不太理解，可以理解了，因为上来就直接的进行了i++，所以设定为-1，如果，设定为0可能有问题
        int i = -1,step = 0, count = n;
        while(count > 0){   //跳出循环时将最后一个元素也设置为了-1
            i++;          //指向上一个被删除对象的下一个元素。
            cout << "i " << i << endl;
            // if(i >= n) i=0;  //模拟环。这里可以思索一下，如果不去重新赋值，而是直接取余是否也是可以的呢,经过测试，取余也是可以的
            if(flag[i % n] == -1) continue; //跳过被删除的对象。
            step++;                     //记录已走过的。
            if(step == m) {               //找到待删除的对象。
                flag[i % n] = -1;
                cout << i << " flag is " << flag[i % n] << endl;
                step = 0;
                count--;
            }        
        }
        cout << "the last char is " << i % n << endl;
        return i;//返回跳出循环时的i,即最后一个被设置为-1的元素
    }

};


int main(int argc, char const *argv[])
{
    Solution s ;
    int t = 0;
    // cout << "my coding is " << endl;
    // s.LastRemaining_Solution(5,3);
    cout << "other coding is " << endl;
    s.LastRemaining_Solution_0(5,3);
        
    return 0;
}
