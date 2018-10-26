/**
统计所有小于非负整数 n 的质数的数量。

示例:
输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
*/

/**
解题思路：
个人想到的方法就是时间复杂度为O(n^2)
考虑一下还有没有优化的方法
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


class Solution 
{
    public:
        int countPrimes(int n) 
        {
            int count = 0;
            if(n <= 1) return count;
            if(n == 2) count += 1;
            
            // 每次只需要计算奇数就可以了
            for(int i = 3; i < n;i += 2)
            {
                if(isPrime(i)) count++;
            }

            return count;
        }
        // 用来判断是否是一个质数
        // 使用下面这个函数，不会通过的
        bool isPrime(int n)
        {
            bool ret = true;
            // 效率略微中等的算法
            if(n == 3) return true;
            for(int i = 2;i <= sqrt(n);i++)
            {
                if (n % i == 0)
                {
                    ret = false;
                    break;
                }
            }
            return ret;
        }
        // 另一种高效的算法
        // 博客链接 https://blog.csdn.net/songyunli1111/article/details/78690447
        // 思路：素数要出现只可能出现在6x的相邻两侧
        bool isPrime_3( int num )
        {
            //两个较小数另外处理
            if(num == 2 || num ==3 )
                            return true ;
            //不在6的倍数两侧的一定不是质数
            if(num %6 != 1 && num %6 != 5)
                            return false ;
            int tmp = sqrt( num);
            //在6的倍数两侧的也可能不是质数
            for(int i = 5 ;i <= tmp; i += 6 )
                            if(num % i == 0||num %(i + 2) == 0 )
                                            return false ;
            //排除所有，剩余的是质数
            return true ;
        }

};

// 另一种解法，通过增加空间复杂度来判断
class Solution_ {
public:
    int countPrimes(int n) {
        bool* no_prime = new bool[n];
        for(int i = 0;i < n;++i)
            no_prime[i] = false;
        
        
        int result=0;
        for(int i = 2;i*i < n;i++){
            if(no_prime[i] == false){
                for(int j = i;i*j < n;j++){
                    no_prime[i*j] = true;
                }
            }
        }
        
        for(int i = 2;i < n;i++){
            if(no_prime[i]==false)
                result++;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

