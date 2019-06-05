/*
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*解题思路：
1.动态规划
2.递归
3.递推
*/
class Solution {
public :
    // 此处采用递归来操作
    int Fibonacci_0(int n){
         if(n == 0)
            return 0;
        else if (n == 1|| n == 2)
        {
            return 1;
        }
        else if (n == 3)
        {
            return 2;
        }
        else 
        {
            // 如果采用下面这一句，时间复杂度非常高，因为存在多次重复计算的问题
            //return Fibonacci(n - 1) + Fibonacci(n - 2);
            // 如果采用下面这一句，时间复杂度相对比较低
            return  3*Fibonacci(n-3)+2*Fibonacci(n-4);
        }
    }
    // 动态规划版本，时间复杂度比较低
    // 代码有些难，看不懂
    int Fibonacci_1(int n){
        //预定义f,g
        int f = 0, g = 1;
        while(n--) {
            // 这里的算法非常巧妙，很好，很难想到
            g += f;
            f = g - f;
        }
        return f;
    }
    // 递推版本,和那个动态规划的版本差不多
    int Fibonacci_2(int n){
        int preNum=1;
        int prePreNum=0;
        int result=0;
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        // 递推计算
        for(int i=2;i<=n;i++){
            result=preNum+prePreNum;
            prePreNum=preNum;
            preNum=result;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    /* code */

    return 0;
}




