/**
冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
现在，给出位于一条水平线上的房屋和供暖器的位置，找到可以覆盖所有房屋的最小加热半径。
所以，你的输入将会是房屋和供暖器的位置。你将输出供暖器的最小加热半径。
说明:
给出的房屋和供暖器的数目是非负数且不会超过 25000。
给出的房屋和供暖器的位置均是非负数且不会超过10^9。
只要房屋位于供暖器的半径内(包括在边缘上)，它就可以得到供暖。
所有供暖器都遵循你的半径标准，加热的半径也一样。
示例 1:

输入: [1,2,3],[2]
输出: 1
解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
示例 2:

输入: [1,2,3,4],[1,4]
输出: 1
解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。
*/

/**
解题思路：
1. 对于每个房屋，要么用前面的暖气，要么用后面的，二者取近的，得到距离；
2. 对于所有的房屋，选择最大的上述距离。
*/

#include <iostream>
#include <vector>

using namespace std;


class Solution 
{
    public:
        int findRadius(vector<int>& houses, vector<int>& heaters) 
        {
            // 对房屋和取暖器排序
            sort(heaters.begin(),heaters.end());
            // 需要查找的最小半径
            int res = 0;
            for(int i = 0,j = 0;i < houses.size();i++)
            {
                // 定义每个取暖器的最小半径
                // 注意这里的初始化
                int cur = INT_MAX;
                // 使用lower_bound查找到每个房屋的最近的右边的供暖器
                // 注意返回的指针地址
                auto heater = lower_bound(heaters.begin(),heaters.end(),houses[i]);
                // 如果取暖器存在的话
                if(heater != heaters.end())
                {
                    // 计算距离
                    cur = *heater - houses[i];
                }
                //如果这个元素没有小于最开始的元素 那么意味着它左边也有一个供暖器
                if(heater != heaters.begin())
                {
                    // 计算左边的距离,以及最小的距离
                    cur = min(houses[i] - *(heater - 1),cur);
                }
                // 返回最大的距离
                res = max(res,cur);

            }
            return res;

        }
};

class Solution_
{
    public: 
        int findRadius(vector<int>& houses, vector<int>& heaters) 
        {
            // 对房屋和取暖器排序
            sort(houses.begin(),houses.end());
            sort(heaters.begin(),heaters.end());
            // 定义每个房屋的最小半径
            vector<int> res(houses.size(),INT_MAX);
            // 先前序的计算房屋取暖的距离
            for(int i = 0,j = 0;i < houses.size() &&j < heaters.size();)
            {
                if(houses[i] <= heaters[j])
                {
                    res[i] = heaters[j] - houses[i];
                    i++;
                }
                else  j++;
            }
            // 然后后序的计算房屋取暖的距离
            for(int i = houses.size() - 1,j = heaters.size() - 1;i >= 0 && j >= 0;)
            {
                if(houses[i] >= heaters[j])
                {
                    res[i] = min(houses[i] - heaters[j],res[i]);
                    i--;
                }
                else j--;

            }
            int cur = INT32_MIN;
            for(auto c:res)
            {
                cur = max(cur,c);
            }
            return cur;
        }
};