/**
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明: 叶子节点是指没有子节点的节点。

示例:
给定二叉树 [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.
*/

/**
解题思路：
递归处理
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){} 
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        //容易出错的点是，遇到一个节点为NULL就返回0，其实应该在叶子节点处才返回0，其他的null节点不用管
        if(!root ) return 0;
        // if(!root -> left && !root -> right) return 1;
        if(!root -> left && root -> right) return minDepth(root -> right) + 1;//记住要加1
        if(!root -> right && root -> left) return minDepth(root -> left) + 1;//记住要加1
        return min(minDepth(root -> left),minDepth(root -> right)) + 1;//记住要加1
    }
};


int main(int argc, char const *argv[])
{

    return 0;
}


