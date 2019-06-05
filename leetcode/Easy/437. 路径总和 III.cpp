/***
给定一个二叉树，它的每个结点都存放着一个整数值。
找出路径和等于给定数值的路径总数。
路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1
返回 3。和等于 8 的路径有:
1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11
**/

/**
解题思路： 不会
深度优先搜索加回溯法
记忆搜索，主要思想：记录深度搜索时——从根节点往下的累积和（记为当前和cur），并每次将cur出现次数+1。
（stl map key如果不存在会自动初始化为0）。
下次使用m[cur-sum]如果为一个非0值，则说明从当前节点往上追溯（不一定追溯到根节点）可能存在一个或多个符合的路径。
（比如，假设目标和为8，假设当前节点为x，假设有路径4->4和4->4->1->-1->x则都符合）。
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


using namespace std;


struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 大神的代码，不懂
class Solution 
{
    public:
        int pathSum(TreeNode* root, int sum) 
        {
            unordered_map<int, int> m;//memory
            m[0] = 1;//cur - sum = 0, return 1
            return dfs(root, sum, 0, m);

        }
        int dfs(TreeNode* node, int sum, int cur, unordered_map<int, int>& m) 
        {
            if (!node) 
            {
                return 0;
            }
            cur += node->val;
            int ans = m[cur - sum];
            ++m[cur];
            ans += dfs(node->left, sum, cur, m) + dfs(node->right, sum, cur, m);
            --m[cur];
            return ans;
    }
};

// 最容易理解的方法
class Solution_1 {
public:
    int pathSum(TreeNode* root, int sum) {
        int cnt = 0;
        dfs1(root, sum, cnt);
        return cnt;
        }
    //dfs用来计算二叉树中符合要求的路径的长度
    void dfs(TreeNode* root, int sum, int& cnt){
         if(root == NULL) return;
        //累计符合要求的路径个数
       if(root->val == sum) cnt++;
        dfs(root->left, sum-root->val, cnt);
        dfs(root->right, sum-root->val, cnt);
     }
    //用来遍历每个节点
    void dfs1(TreeNode* root, int sum, int& cnt){
         if(root == NULL) return;
        dfs(root, sum, cnt);
        dfs1(root->left, sum, cnt);
        dfs1(root->right, sum, cnt);
    }
 
};

// 递归+深度搜索
class Solution_
{
    public:
        int pathSum(TreeNode* root, int sum) 
        {
            if(!root) 
            {
                return 0;
            }
            int left = pathSum(root->left, sum);
            int right = pathSum(root->right, sum);
            int r = dfs(root, sum);
            return left + right + r; 
        }
        
        int dfs(TreeNode* root, int sum)
        {
            if(!root)
            {
                return 0;
            }
            int hit = (root -> val == sum) ? 1 : 0;
            int left = dfs(root->left, sum - root->val);
            int right = dfs(root->right, sum - root->val);
            return hit + left + right;
        }
};



int main(int argc, char const *argv[])
{
    return 0;
}
