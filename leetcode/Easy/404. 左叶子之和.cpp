/**
计算给定二叉树的所有左叶子之和。

示例：
    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
*/

/**
解题思路：
递归求和 
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        int sumOfLeftLeaves(TreeNode* root) 
        {
            int sum = 0;
            if(!root) return 0;
            getSum(root,false,sum);
            return sum;
        }
        // 定义计算左叶子和的函数
        // 递归计算
        void getSum(TreeNode *root,bool flag,int &sum)
        {
            if(!root -> left && !root -> right && flag)
            {
                sum += root -> val;
            }
            if(root -> left) getSum(root -> left,true,sum);
            if(root -> right) getSum(root -> right,false,sum);
            return;
        }
};

int main(int argc, char const *argv[])
{
    return 0;
}
