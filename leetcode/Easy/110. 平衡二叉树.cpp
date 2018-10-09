/**
给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:
给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:
给定二叉树 [1,2,2,3,3,null,null,4,4]
       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。 
*/

/**
解题思路：
参加剑指offer
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>


using namespace std;


struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){}
};

class Solution{
public :
    bool isBalanced(TreeNode* root) 
    {
        // if(!root) return true;
        // int left = maxDepth(root -> left);
        // int right = maxDepth(root -> right);
        // if(abs(left - right) >= 2) return false;
        // return isBalanced(root -> left) && isBalanced(root -> right );    
        // 优化的调用
        return isFun(root) != -1;  
    }

    // 最简单的方法就是每次去计算左右子树的深度，然后对比
    // 但是这样子的话，会有多次重复计算
    int maxDepth(TreeNode *root)
    {
        if(!root) return 0;
        return max(maxDepth(root -> left),maxDepth(root -> right)) + 1;
    } 
    // 优化计算，去除冗余
    int isFun(TreeNode* root)
    {
        if(root == NULL) return 0;
        int left = isFun(root -> left);
        // 直接来判断是不是是平衡树
        if(left == -1) return -1;
        int right = isFun(root -> right);
        if(right == -1) return -1;
        // 注意这里的递归调用
        return abs(left - right) > 1 ? -1 : max(isFun(root -> left),isFun(root -> right)) + 1;
    }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}



