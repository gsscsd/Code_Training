/**
给定一个已按照升序排列的有序数组，找到两个数使得它们相加之和等于目标数。
函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

说明:
返回的下标值（index1 和 index2）不是从零开始的。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。

示例:
输入: numbers = [2, 7, 11, 15], target = 9
输出: [1,2]
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
*/


/**
解题思路：
剑指offer 的题目
1.双指针,头尾指针
2.利用升序排列这个条件
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums,int target)
        {
            vector<int> result;
            if(nums.size() <= 1) return result;
            int head = 0,tail = nums.size() - 1;
            while(head < tail)
            {
                if(target == nums[head] + nums[tail])
                {
                    result.push_back(head + 1);
                    result.push_back(tail + 1);
                    break;
                }
                // 否则的话，调节头尾指针
                // z注意下面的头尾指针的用法
                while(head < tail && nums[head] + nums[tail] > target) --tail;
                while(head < tail && nums[head] + nums[tail] < target) ++head;
            }
            return result;
        }
};

// int main(int argc, char const *argv[])
// {
//     long long n;
//     cin >> n;
//     long long result = n * n;
//     cout << result << endl;
//     return 0;
// }
