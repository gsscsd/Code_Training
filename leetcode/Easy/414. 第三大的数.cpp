/**
给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。要求算法时间复杂度必须是O(n)。
示例 1:
输入: [3, 2, 1]
输出: 1
解释: 第三大的数是 1.
示例 2:
输入: [1, 2]
输出: 2
解释: 第三大的数不存在, 所以返回最大的数 2 .
示例 3:
输入: [2, 2, 3, 1]
输出: 1
解释: 注意，要求返回第三大的数，是指第三大且唯一出现的数。
存在两个值为2的数，它们都排第二。
*/

/**
解题思路：
小象学院碰见过的题目
*/

#include <iostream>
#include <vector>
#include <set>


using namespace std;

class Solution 
{
    public:
        int thirdMax(vector<int>& nums) 
        {
            int first = INT_MIN, second = INT_MIN, third = INT_MIN, f = INT_MAX;
            for (int i = 0; i < nums.size(); ++i)
            {
                f = min(f, nums[i]);//The smallest number that appears
                if (nums[i] > first){
                    // 巧妙的交换方法
                    third = second, second = first, first = nums[i];
                }else if (nums[i] > second && nums[i] < first)
                {
                    third = second, second = nums[i];
                }else if (nums[i] > third && nums[i] < second) 
                {
                    third = nums[i];
                }
            }
            return second > third && third >= f ? third : first;
        }
};


class Solution_ 
{
    public:
        int thirdMax(vector<int>& nums) 
        {
            set<int> s;
            for(auto num : nums) 
            {
                s.insert(num);
                if(s.size() > 3)
                    s.erase(s.begin());
            }
            return s.size() == 3 ? *s.begin() : *s.rbegin();
        }
};   


int main(int argc, char const *argv[])
{
    return 0;
}
