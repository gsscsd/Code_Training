/**
给定一个 32 位有符号整数，将整数中的数字进行反转。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。
根据这个假设，如果反转后的整数溢出，则返回 0。
*/

/**
解题思路：
*/

#include <iostream>
#include <vector>
#include <algorithm>

// 先定义边界，然后判定是否出界
#define INT_MAX 0x7FFFFFFF
#define INT_MIN -INT_MAX-1
// #define int_min 0x8FFFFFFF


using namespace std;


class Solution {
public:
    // 网上似乎还有不用区分正负数的算法
    // 实际上代码不用区分正负数
    int reverse(int x) {
        // bool flag = x < 0;
        // 假设x是-2147483648,那么对x取反会溢出，所以，先赋值给long的类型，防止溢出
        long t = x;
        // 首先如果是负数，那么对t取反
        // if(flag) t = - t;
        // 定义反转的数
        long m = 0;
        while(t != 0)
        {
            m = m * 10 + (t % 10);
            t /= 10;
        }
        // 计算完成后，将负数在转换回去
        // if(flag) m = -m;
        // 判定是否溢出
        if(m > INT_MAX || m < INT_MIN)
        {
            return 0;
        }
        // 注意m是long的类型，所以此时需要向下取整
        return (int)m;
    }
    // 网上处理的方式，不用考虑正负数，然后边界放在循环里面来考虑
    int reverse_(int x) {
        int result(0);
        while (x != 0) {
            int newResult = result * 10 + x % 10;
            if ((newResult - x % 10) / 10 != result) {
                return 0;
            }
            result = newResult;
            x = x / 10;
        }
        
        return result;
    }
    // 第三种
     int reverse_1(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            // 每次组成的时候，进行溢出检查
            // 这一句检查是否是正数溢出
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            // 这一句检查是否是负数溢出
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};



int main()
{
    int x ;
    cin >> x;
    Solution s;
    int m = s.reverse(x);
    cout << "result is " << m << endl;
    return 0;
}