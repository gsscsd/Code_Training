/**
给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。

示例 1:
输入: nums = [1,2,3,1], k = 3
输出: true

示例 2:
输入: nums = [1,0,1,1], k = 1
输出: true

示例 3:
输入: nums = [1,2,3,1,2,3], k = 2
输出: false
*/

/**
解题思路：
暴力查找：
时间复杂度为O(n^2),空间复杂度为O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution 
{
    public:
        // 暴力查找
        bool containsNearbyDuplicate(vector<int>& nums, int k) 
        {
            int num_len = nums.size();
            for(int i = 0;i < num_len;i++)
            {
                for(int j = i + 1;j < num_len;j++)
                {
                    if(nums[i] == nums[j] && (j - i <= k))
                    {
                        return true;
                    }
                }
            }
            return false;
        }
};

// 高票答案二
// 时空复杂度为O(n)
// 使用map来做映射 key为nums[i],value为i
class Solution__ {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> my_map;
        for(int i=0;i<nums.size();++i)
        {
            if(!my_map.count(nums[i]))
            {
                my_map[nums[i]] = i;
            }
            else 
            {
                int num = i - my_map[nums[i]];
                if(num <= k) return true;
                else my_map[nums[i]] = i;
            }

        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}

