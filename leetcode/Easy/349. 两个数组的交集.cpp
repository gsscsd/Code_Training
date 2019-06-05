/**
给定两个数组，编写一个函数来计算它们的交集。

示例 1:
输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]

示例 2:
输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]
说明:

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。
 */

/**
解题思路：
1.map映射
2.双指针遍历
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;


// 空间为n，时间为n
class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
        {
            vector<int> vec;
            map<int,int> mp1,mp2;
            for(int i = 0;i < nums1.size();i++)
            {
                if(!mp1.count(nums1[i])) mp1[nums1[i]] = 1;
                else mp1[nums1[i]] += 1;
            }
            for(int i = 0;i < nums2.size();i++)
            {
                if(!mp2.count(nums2[i])) mp2[nums2[i]] = 1;
                else mp2[nums2[i]] += 1;
            }
            map<int,int>::iterator iter1 = mp1.begin();
            map<int,int>::iterator iter2 = mp2.begin();
            while(iter1 != mp1.end() && iter2 != mp2.end())
            {
                if(iter1 -> first == iter2 -> first) 
                {
                    vec.push_back(iter1 -> first);
                    iter1++,iter2++;
                }
                if(iter1 -> first < iter2 -> first) iter1++;
                if(iter1 -> first > iter2 -> first) iter2++;
            }
            return vec;
        }
};

// 使用排序加双指针算法
// 时间nlogn,空间为1
class Solution_ {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int a=0,b=0,n=0;
        while(a<nums1.size()&&b<nums2.size())
        {
            if(nums1[a]<nums2[b]) a++;
            else if(nums1[a]>nums2[b]) b++;
            else 
            {
                // 注意这里的技巧
                if(res.empty()||res.back()!=nums1[a])
                {
                    res.push_back(nums1[a]);
                    a++;
                }
                else a++;
            }
        }
        return res;
    }
};



int main(int argc, char const *argv[])
{
    return 0;
}


