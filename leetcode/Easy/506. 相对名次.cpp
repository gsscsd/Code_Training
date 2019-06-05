/**
给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 
“金牌”，“银牌” 和“ 铜牌”（"Gold Medal", "Silver Medal", "Bronze Medal"）。
(注：分数越高的选手，排名越靠前。)
示例 1:
输入: [5, 4, 3, 2, 1]
输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal" and "Bronze Medal").
余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。
提示:
    N 是一个正整数并且不会超过 10000。
    所有运动员的成绩都不相同。
*/

/**
解题思路：
排序然后，，，
*/

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution 
{
    public:
        // sort排序第三个参数，需要指定函数
        bool cmp(int a,int b)
        {
            return a > b;
        }
        vector<string> findRelativeRanks(vector<int>& nums) 
        {
            vector<string> res(nums.size(),"");
            // 定义temp用来进行保存排序之后的数字
            vector<int> temp = nums;
            // 使用系统提供的排序算法
            // sort(nums.begin(),nums.end(),cmp);
            // 使用lambda表达式
            sort(temp.begin(),temp.end(),[](int a, int b) -> bool { return a < b; });
            unordered_map<int, string> m;
            m[temp[0]] = "Gold Medal";
            m[temp[1]] = "Silver Medal";
            m[temp[2]] = "Bronze Medal";
            // 使用key-value保存数字和名次
            for(int i = 3;i < nums.size();i++)
            {
                m[temp[i]] = to_string(i + 1);
            }
            // 保存到res里面
            for(int i = 0;i < nums.size();i++){
                res[i] = m[nums[i]];
            }
            return res;
        }
};