/**
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。
**/

/**
解题思路：
1.暴力遍历
2.二分查找
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int len = nums.size();
        if(len == 0) return 0;
        int low = 0,high = len - 1;
        if(target < nums[0]) return 0;
        if(target > nums[len - 1]) return len;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else if(nums[mid] > target)
            {
                high = mid - 1;
            }
            else 
            {
                return mid;
            }
        }
        cout << "low is " << low << " high is " << high << endl;
        return low;    
    }
};


int main()
{
    vector<int> vec;
    // for(int i = 0;i < 5;i++)
    // {
    //     vec.push_back(i);
    // }
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(6);
    Solution s;
    int index = s.searchInsert(vec,4);
    cout << index << endl; 
    return 0;
}