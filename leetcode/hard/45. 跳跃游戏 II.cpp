/**
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:
输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
解题思路
1. 贪婪算法，我们每次在可跳范围内选择可以使得跳的更远的位置
在到达某点前，若一直不跳跃，如果发现从该点无法跳跃更远的地方了，在这之前，肯定有一次必要的跳跃
在无法到达更远的地方时，在这之前应该跳到一个可以到达更远位置的位置

2. 我们知道最终要到达最后一个位置，然后我们找前一个位置，遍历数组，找到能到达它的位置，离它最远的就是要找的位置。然后继续找上上个位置，最后到了第 0 个位置就结束了。
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // 更容易理解的答案
    int jump(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return 0;
        }
        // 步数
        int jump = 0;
        // 当前的位置
        int cur = 0;
        // 下一步的位置
        int next = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (cur < i)
            {
                jump++;
                cur = next;
            }
            // 跳到最远的位置
            next = max(next, i + nums[i]);
        }
        return jump;
    }

    // 从后向前跳O(n^2)
    int jump1(vector<int> &nums)
    {
        int position = nums.size() - 1; //要找的位置
        int steps = 0;
        while (position != 0)
        { 
            //是否到了第 0 个位置
            for (int i = 0; i < position; i++)
            {
                if (nums[i] >= position - i)
                {
                    position = i; //更新要找的位置
                    steps++;
                    break;
                }
            }
        }
        return steps;
    }
};