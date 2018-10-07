/**
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，
    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度3。
*/

/**
解题思路：
剑指offer的题目
递归或者非递归
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x ):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // 如果当前节点为NULL，直接返回0
        if(!root) return 0;
        int left = maxDepth(root -> left) + 1;
        int right = maxDepth(root -> right) + 1;
        return max(left,right);
    }
};

int main()
{
    return 0;
}



