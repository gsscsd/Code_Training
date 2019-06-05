/**
给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。
nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出-1。
示例 1:
输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
    对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
    对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。
示例 2:
输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
    对于num1中的数字2，第二个数组中的下一个较大数字是3。
    对于num1中的数字4，第二个数组中没有下一个更大的数字，因此输出 -1。
注意:
nums1和nums2中所有元素是唯一的。
nums1和nums2 的数组大小都不超过1000。
*/

/**
解题思路：
通过Stack、HashMap解决
    先遍历大数组nums2，首先将第一个元素入栈；
    继续遍历，当当前元素小于栈顶元素时，继续将它入栈；当当前元素大于栈顶元素时，栈顶元素出栈，此时应将该出栈的元素与当前元素形成key-value键值对，存入HashMap中；
    当遍历完nums2后，得到nums2中元素所对应的下一个更大元素的hash表；
    遍历nums1的元素在hashMap中去查找‘下一个更大元素’，当找不到时则为-1。
*/

#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>

using namespace std;

class Solution 
{
    public:
        vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) 
        {
            // 定义需要返回的数组
            vector<int> res(findNums.size(),-1);
            // 定义单调栈
            stack<int> st;
            // 定义每个元素与下一个元素的key-value
            map<int,int> mp;
            for(auto num : nums)
            {
                // 注意这里的代码，使用while一直来构建mp
                while(!st.empty() && st.top() < num)
                {
                    mp[st.top()] = num;
                    st.pop();
                }
                st.push(num);
            }
            for(int i = 0; i < findNums.size();i++)
            {
                auto it = mp.find(findNums[i]);
                if(it != mp.end())
                {
                    res[i] = it -> second;
                }
            }
            return res;
        }
};