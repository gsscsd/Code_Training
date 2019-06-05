/**
给定两个数组，编写一个函数来计算它们的交集。

示例 1:
输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]

示例 2:
输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]

说明：
输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
我们可以不考虑输出结果的顺序。

进阶:
如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小很多，哪种方法更优？
如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？

*/

/**
解题思路：
1.map映射
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

// map映射的方法
class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
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
                    for(int i = 0; i < min(iter1 -> second,iter2 -> second);i++)
                    {
                        vec.push_back(iter1 -> first);
                    }
                    iter1++,iter2++;
                }
                if(iter1 -> first < iter2 -> first) iter1++;
                if(iter1 -> first > iter2 -> first) iter2++;
            }
            return vec;
        }
};

// 排序双指针
class Solution_ {
public:
    /*
    //先排序，然后用两个指针分别指向两个数组的开头，然后比较两个数组的大小，把小的数字的指针向后移，如果两个指针指的数字相等，就将数字添加到vector中
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        if(nums1.empty()||nums2.empty())
            return vec;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int len1 = nums1.size();
        int len2 = nums2.size();
        for(int index1=0, index2=0;index1<len1&&index2<len2;)
        {
            if(nums1[index1] == nums2[index2])
            {
                vec.push_back(nums1[index1]);
                ++index1;
                ++index2;
            }
            else if(nums1[index1] < nums2[index2])
                ++index1;
            else
                ++index2;
        }
        return vec;
    }
    */
    
    //利用hash表先对其中一个数组中的元素建立表，然后再对第二个数组进行遍历，如果在hash表中关键词对应的关联值为正数，那么就添加到vector中，并且hash表中的关联词减一
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        if(nums1.empty() || nums2.empty())
        {
            return vec;
        }
        unordered_map<int, int> m;
        for(auto n: nums1) ++m[n];
        for(auto a: nums2)
        {
            if(m[a]-- > 0)
                vec.push_back(a);
        }
        return vec;
    }
    
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
