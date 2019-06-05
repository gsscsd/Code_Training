/**
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]
示例 2:

输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

/**
解题思路：
递归+枚举+回溯
*/

#include <bits/stdc++.h>

using namespace std;

/*递归+回溯。
搞清思路，就很容易理解了。
定义一个dfs(v, index)：从向量区间[index, v.size())找一个子集。
考虑两种情况：
1. [index, v.size()) 区间大小为0，那么此区间之间的结果可以返回了。
 (区间大小为0时，index>=v.size())
2. 每次从区间[index, v.size())区间开始找的时候，都可以取空集[]作为一个解.
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> temp;
        // 先排序，然后方便后续操作
        sort(candidates.begin(),candidates.end());
        // 宽优先遍历
        bfs(candidates,res,temp,target,0);
        return res;
    }
    void bfs(vector<int> & candidates,vector<vector<int> > &res,vector<int> & temp,int target,int l)
    {
        if(target == 0)
        {
            res.push_back(temp);
        }
        if(target < 0 ) return;
        // 注意每次是从上一次的节点开始出发，这样会一直减去上一个节点
        // 这里决定了是否包含重复的数据
        for(int i = l;i < candidates.size() ;i++)
        {
            // 压入数据
            temp.push_back(candidates[i]);
            // 递归运算
            bfs(candidates,res,temp,target - candidates[i],i);
            // 弹出数据
            temp.pop_back();

        }
    }
};

class Solution_1 {
public:
    vector<vector<int>> ans;
    vector<int> t;
    void dfs(int i, int target, const vector<int>& candidates)
    {
        if(!target){
            ans.push_back(t);
            return;
        }
        if(i == candidates.size())return;    
        if(target >= candidates[i]){
            t.push_back(candidates[i]);
            // 深度遍历
            dfs(i, target - candidates[i], candidates);
            t.pop_back();
        }
        dfs(i + 1, target, candidates);
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        dfs(0, target, v);
        return ans;
    }
};