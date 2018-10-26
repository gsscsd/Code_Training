/**
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:
输入: [3,2,3]
输出: 3

示例 2:
输入: [2,2,1,1,1,2,2]
输出: 2
*/
/**
解题思路：
参考剑指offer的代码
1.map
2.使用删除的方法
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution
{
    public:
        int majorityElement(vector<int>& nums) 
        {
            // 做边界控制
            if(nums.size() < 1) return -1;
            map<int,int> mp;
            int res = nums[0];
            for(int i = 0; i < nums.size();i++)
            {
                if(!mp.count(nums[i])) mp[nums[i]] = 0;
                else mp[nums[i]] ++;
            }
            for(int i = 0;i < nums.size();i++)
            {
                if(mp[nums[i]] >= nums.size() / 2) 
                {
                    res = nums[i];
                    break;
                }
            }
            return res;
        }
};


int main()
{
    return 0;
}