/**
题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，
则最小的4个数字是1,2,3,4,。
 */

/**
解题思路：
1.堆排序，小顶堆
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
// 直接调用算法库的算法，理论上直接实现快排或者堆排序
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> null_v;
        if(k > input.size()) return null_v;
        // sort 排序算法
        sort(input.begin(),input.end());
        vector<int> result(input.begin(),input.begin() + k);
        return result;
    }
// 手动实现快排或者是堆排序
};


int main()
{
    vector<int> vec;
    for(int i = 0;i < 8;i++)
    {
        vec.push_back(7 - i);
    }
    Solution s;
    vector<int> result;
    result = s.GetLeastNumbers_Solution(vec,5);
    for(auto &s : result)
    {
        cout << s << endl;
    }

}
