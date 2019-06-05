/**
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
*/

/**
递归回溯，同时要去重。
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


/**
第一种解法，在递归的时候，跳过重复的元素
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> temp;
        // 先排序，然后方便后续操作
        sort(candidates.begin(),candidates.end());
        // 宽优先遍历
        dfs(candidates,res,temp,target,0);
        return res;
    }
    void dfs(vector<int> & candidates,vector<vector<int> > &res,vector<int> & temp,int target,int start)
    {
        if(target == 0)
        {
            res.push_back(temp);
        }
        if(target < 0 ) return;
        // 注意每次是从上一次的节点开始出发，这样会一直减去上一个节点
        // 这里决定了是否包含重复的数据
        for(int i = start;i < candidates.size() ;i++)
        {
            // 此处跳过会重复的元素
            if (i > start && candidates[i] == candidates[i-1]){
                continue;
            }
            // 压入数据
            temp.push_back(candidates[i]);
            // 递归运算
            dfs(candidates,res,temp,target - candidates[i],i + 1);
            // 弹出数据
            temp.pop_back();

        }
    }
};

// 第二种方法使用set去重
class Solution
{
  public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        set<vector<int>> res;
        vector<int> temp;
        // 先排序，然后方便后续操作
        sort(candidates.begin(), candidates.end());
        // 宽优先遍历
        dfs(candidates, res, temp, target, 0);
        return vector<vector<int>>(res.begin(), res.end());
    }
    void dfs(vector<int> &candidates, set<vector<int>> &res, vector<int> &temp, int target, int l)
    {
        if (target == 0)
        {
            res.insert(temp);
        }
        if (target < 0)
            return;
        // 注意每次是从上一次的节点开始出发，这样会一直减去上一个节点
        // 这里决定了是否包含重复的数据
        for (int i = l; i < candidates.size(); i++)
        {
            //  if (i > l && candidates[i] == candidates[i-1]){
            //     continue;
            // }
            // 压入数据
            temp.push_back(candidates[i]);
            // 递归运算
            dfs(candidates, res, temp, target - candidates[i], i + 1);
            // 弹出数据
            temp.pop_back();
        }
    }
};
