/**
给定一个整数数组，判断是否存在重复元素。

如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

示例 1:

输入: [1,2,3,1]
输出: true
示例 2:

输入: [1,2,3,4]
输出: false
示例 3:

输入: [1,1,1,3,3,4,3,2,4,2]
输出: true
*/

/**
解题思路：
感觉上应该使用异或操作
时间复杂度和空间复杂度分别为O(n),O(n)
空间复杂度可能优化到O(1)
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution 
{
    public:
        // 使用map做映射，然后计算频次
        bool containsDuplicate(vector<int>& nums) 
        {
            if(nums.size() <= 1) return false;  
            bool res = false;
            map<int,int> mp;
            for(int i = 0;i < nums.size();i++)
            {
                if(!mp.count(nums[i])) mp[nums[i]] = 1;
                else mp[nums[i]] += 1;
            }
            for(int i = 0; i < nums.size();i++)
            {
                if(mp[nums[i]] >= 2)
                {
                    res = true;
                    break;
                }
            }
            return res;
        }
        // 使用sort对nums排序，然后判断相邻是否相等
        bool containsDuplicate_(vector<int> & nums)
        {
            if(nums.size() <= 1) return false; 
            bool res = false;
            sort(nums.begin(),nums.end());
            for(int i = 1;i < nums.size();i++)
            {
                if(nums[i - 1] == nums[i]) 
                {
                    res = true;
                    break;
                }
            }
            return res;
        }
};


int main(int argc, char const *argv[])
{
    
    
    return 0;
}








