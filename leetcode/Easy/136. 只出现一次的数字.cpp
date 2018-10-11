/**
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:
输入: [2,2,1]
输出: 1

示例 2:
输入: [4,1,2,1,2]
输出: 4
*/

/**
剑指offer的题目
1.暴力设置数组
2.异或操作
*/


#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution 
{
    public: 
        // 最简单的方法，设定一个map来保存
        int singleNumber(vector<int>& nums)
        { 
            map<int,int> mp;
            int result = 0;
            for(int i = 0; i < nums.size();i++)
            {
                if(!mp.count(nums[i])) mp[nums[i]] = 1;
                else mp[nums[i]] += 1;
            }
            for(int j = 0 ;j < nums.size();j++)
            {
                if(mp[nums[j]] == 1) 
                {
                    result = nums[j];
                    break;
                }
            }
            return result;
        }
        int singleNumber_(vector<int>& nums)
        {
            int result = 0;
            if (nums.size() <= 0) 
            {
                return 0;
            }
            for (int index = 0; index < nums.size(); ++index) 
            {
                // 异或操作，相同的数字异或为0
                result ^= nums[index];
            }
            return result;
        }

};

int main()
{
    return 0;
}




