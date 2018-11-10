/**

给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，
垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。



示例:

输入: [1,8,6,2,5,4,8,3,7]
输出: 49 
*/

/**
解题思路：
1. 暴力for循环：时间O(n^2)
2. 双指针类似于167
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 理论上这个题目有简单的方法
// 先用暴力穷举
class Solution 
{
    public:
        int maxArea(vector<int>& height) 
        {
            int result = 0;
            for(int i = 0 ;i < height.size();i++)
            {
                for(int j = i + 1; j < height.size();j++)
                {
                    int area = min(height[i],height[j]) * (j - i );
                    if(result < area)
                    {
                        result = area;
                    }
                }
            }
            return result;
        }
};

class Solution_
{
    public:
        int maxArea(vector<int>& height)
        {
            int result = 0;
            int i = 0,j = height.size() - 1;
            while(i < j)
            {
                int area = min(height[i],height[j]) * ( j - i );
                if(result < area) result = area;
                if (height[i] > height[j]) j--;
                else i++;
            }
            return result;
        }
};

int main(int argc, char const *argv[])
{
    return 0;
}


