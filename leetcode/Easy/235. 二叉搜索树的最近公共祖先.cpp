/**
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
示例 1:
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6 
解释: 节点 2 和节点 8 的最近公共祖先是 6。

示例 2:
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。

说明:
所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉搜索树中。
*/

/**
解题思路：
由题目可以知道是一颗二叉搜索树，所以，可以考虑使用递归来处理
分三种情况来考虑:
思路如下：
有两种情况：1.u,v不在树中；
           2.u,v在树中：<1>u,v都在左子树上；
                       <2>u,v都在右子树上；
                       <3>u,v一个在左子树上，一个在右子树上；
                       <4>u，v有一个在根上。 

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){};
};


class Solution 
{
    public:
        // 将函数递归的来处理，代码考虑的不清晰
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
        {
            if(!root) return NULL;
            // 判断p或者q是否为公共祖先
            if(root == p || root == q) return root ;
            // 寻找最近的祖先
            if((p -> val < root -> val && q -> val > root -> val) || (p -> val > root -> val && q -> val < root -> val))
                return root ;
            // 右子树递归查找
            if(p -> val > root -> val ) return lowestCommonAncestor(root -> right,p,q);
            // 左子树递归查找
            if(p -> val < root -> val ) return lowestCommonAncestor(root -> left ,p,q);
            
        };
};

// 非递归的方法
class Solution_ {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;  
        // 要么在左子树，要么在右子树，要么就是根节点
        while(root){  
            // 祖先是否在右子树
            if(p -> val > root ->val && q -> val > root -> val)  
                root = root -> right;  
            // 祖先是否在左子树
            else if(p -> val < root -> val && q -> val < root -> val)  
                root = root->left;  
            else return root;  
        } 
    }
};
