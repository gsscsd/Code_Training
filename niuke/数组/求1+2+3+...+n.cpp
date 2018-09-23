/***
题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

/**
解题思路：
短路求值原理
*/

#include <iostream>
#include <vector>
#include <string>


using namespace std;



class Solution {
public:
    // 果断放弃，看答案了
    int Sum_Solution(int n) {
        int ans = n;
        // 如果不要求循环，那么考虑递归处理
        // 下面这一句话是递归的边界，应用了&&短路特性，因为只要n-1一直减下去、
        // 就会出现0的情况，此时，到达递归边界
        ans && (ans += Sum_Solution(n - 1));
        return ans;
    }
};

int main(int argc, char const *argv[])
{
        
        return 0;
}
