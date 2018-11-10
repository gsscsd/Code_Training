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
    解题：定义一个m和c，m是候选的众数，c代表次数，
    每次判断m与A[i]是否相同，如果不相同就同时删除
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
            // 设定一个map，key为nums[i],value为出现的次数
            map<int,int> mp;
            int res = nums[0];
            // 第一次for循环，统计每个nums[i]的频次
            for(int i = 0; i < nums.size();i++)
            {
                if(!mp.count(nums[i])) mp[nums[i]] = 0;
                else mp[nums[i]] ++;
            }
            // 第二次for循环，找到频次大于2分之一的
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
        int majorityElement_(vector<int>& nums)
        {
            if(nums.size() == 1) return nums[0];
            int m = nums[0],c = 0;
            for(int i = 1; i < nums.size();i++)
            {
                if(c == 0)
                {
                        m = nums[i];
                        c = 1;
                }
                else if (m != nums[i])
                {
                        c--;
                }
                else c++;
            }
            return m;
        }
};


int main()
{
    return 0;
}

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() / 2 ;
        for(int i = 0; i < nums.size();i++)
        {
            int count = 0;
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[i] == nums[j])
                {
                    count++;
                }          
            }
            if(count > n) return nums[i];
        }
    }
};