/**
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1] 
*/

/**
解题思路：
1.循环遍历
2.map表实现
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    // 暴力for循环，时间复杂度为o(n^2),空间复杂度为O(1) 200ms
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        for(int i = 0;i < nums.size();i++)
        {
            for(int j = i + 1;j < nums.size();j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    vec.push_back(i);
                    vec.push_back(j);
                    break;
                }
            }
        }
        return vec;
    }
    // 优化后，8ms
    vector<int> twoSum_(vector<int>& nums, int target) {
        // 使用unordered_map来存储数据，第一个是数，第二个是下标
        // 貌似使用map也可以
        map<int,int> mtemp;
        vector<int> vec;
        // 第一遍将所有的数据插入到map里面,注意，没有重复的数字，所以键值唯一
        for(int i = 0;i < nums.size();++i)
        {
            mtemp[nums[i]] = i;
        }
        // 第二遍扫描查找
        for (int i=0; i<nums.size(); ++i){
            // 从map中查找是否存在元素
            int nextval = target - nums[i];
            // 如果存在并且下标不为i
            if( mtemp.count(nextval) && mtemp[nextval] != i){
                // 保存并且推出
                vec.push_back(i);
                vec.push_back(mtemp[nextval]);
                break;
            }
        }
        return vec;
    }
};
