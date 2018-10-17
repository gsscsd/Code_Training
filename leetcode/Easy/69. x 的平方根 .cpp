/**
实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:
输入: 4
输出: 2

示例 2:
输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
*/
/**
解题思路：
1.牛顿法
计算 f(t) = t^2 - x 的根，迭代计算方法如下
x(n+1) = x(n) - f(x(n)) / f'(x(n))
2.二分法
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        double eps = 1e-5;
        double result = x;
        double last = x;
        while(1)
        {
            // 这里的last是为了保留上一个结果，并计算结果之间的差值
            last = result;
            // 注意此处的牛顿法的公式,后面那个加0.00001是为了防止出现除零错误
            // result = result - (result * result - x) / 2.0 / result;
            result = result - (result * result - x) / 2.0 / (result + 0.000001);
            if(abs(result - last) < eps)
            {
                break;
            } 
        }
        return (int)result;
    }
};

class Solution_ {
public:
    int mySqrt(int x) {
        if(x == 1 || x == 0)
            return x;
        double x1 = x1,x2 = x / 2;
       
        while(abs(x1 - x2) > 0.001)
        {
            x1 = x2;
            x2 = (x1 + x / x1) / 2;
           
        }
        return (int)x2;
    }
};

int main()
{
    Solution s;
    int t = s.mySqrt(4);
    cout << t << endl;
    return 0;
}
