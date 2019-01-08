/***
我们正在玩一个猜数字游戏。 游戏规则如下：
我从 1 到 n 选择一个数字。 你需要猜我选择了哪个数字。
每次你猜错了，我会告诉你这个数字是大了还是小了。
你调用一个预先定义好的接口 guess(int num)，它会返回 3 个可能的结果（-1，1 或 0）：

-1 : 我的数字比较小
 1 : 我的数字比较大
 0 : 恭喜！你猜对了！
示例 :

输入: n = 10, pick = 6
输出: 6
*/

/**
解题思路：
折半查找？？？
直接二分查找即可
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int guess(int num);

class Solution 
{
    public:
        int guessNumber(int n) 
        {
            if(guess(n) == 0) return n;
            int low = 0;
            int high = n;
            while(low < high)
            {
                int mid = low / 2 + high / 2;
                if(0 == guess(mid)) return mid;
                if(guess(mid) > 0 ) low = mid + 1;
                if(guess(mid) < 0 ) high = mid - 1;
            }
            return low;
        }
};



int main()
{
    return 0;
}