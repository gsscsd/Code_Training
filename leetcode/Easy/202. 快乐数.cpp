/**
编写一个算法来判断一个数是不是“快乐数”。

一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。如果可以变为 1，那么这个数就是快乐数。

示例: 

输入: 19
输出: true
解释: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

/**
解题思路：
1.迭代计算就可以了
2.考虑使用set这个函数
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

class  Solution 
{
    public:
        bool isHappy(int n)
        {
            bool res = false;
            // 如果在迭代计算的过程中，出现和原数相等的那么就是false
            while(n)
            {
                // 在转换的过程中是否可以通过字符串呢？
                string s = to_string(n);
                // 讲n先清零
                n = 0;
                // for(int i = 0;i < s.size();i++)
                // {
                //     n += pow(s[i] - '0',2);
                // }
                // 以上是采用字符串的用法
                // 以下是采用取余的算法
                int t = 0;
                while (n) {
                    t += (n % 10) * (n % 10);
                    n /= 10;
                }
 
                if(n == 1)
                {
                    res = true;
                    break;
                }
                // 经过测试，如果出现4，那么就是死循环
                if(4 == n)
                {
                    res = false;
                    break;
                }
            }
            return res;
        }
};

// 题目如下所示的采用set的方法
class Solution_ {
public:
    bool isHappy(int n) {
      set<int> s;
        while (n != 1) {
            int t = 0;
            while (n) {
                t += (n % 10) * (n % 10);
                n /= 10;
            }
            n = t;
            if (s.count(n)) break;
            else s.insert(n);
        }
        return n == 1;
    }
};


int main(int argc, char const *argv[])
{
        
    return 0;
}

