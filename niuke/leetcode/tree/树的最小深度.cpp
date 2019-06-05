// 题目描述
// Given a binary tree, find its minimum depth.
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
#include <iostream>
#include <string>
#include <algoririthm>
using namespace std;


class Solution{
    public:
    int run(TreeNode *root)
    {
        if(!root) return 0;
        else if (!root -> left) return run(root->right) + 1;
        else if (!root -> right) return run(root->left) + 1;
        else{
            return min(run(root->left),run(root->right)) + 1;
        }
    }
};






