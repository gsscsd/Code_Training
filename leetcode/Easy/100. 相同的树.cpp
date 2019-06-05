/**
给定两个二叉树，编写一个函数来检验它们是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1:
输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

输出: true
示例 2:
输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

输出: false
示例 3:
输入:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]
输出: false
*/

/**
解题思路：
参加剑指offer
递归判断，注意，递归体和递归边界
*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    // 找出所有的false的结果以及，true的结果
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // 以下是leetcode的高票答案
        // 如果q，p同时为空，说明都一样，那么就返回true
        // if(p==NULL && q==NULL)
        //     return true;
        // // 如果q或者p之中有一个为空，返回false
        // if(p==NULL || q==NULL)
        //     return false;
        // // 如果，pq的值相等，那么就判断他们左子树和右子树是否相同
        // if(p->val==q->val)
        //     return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        // return false;

        if(p != NULL && q == NULL) return false;
        if(p == NULL && q != NULL) return false;
        if(p && q)
        {
            if(p -> val == q -> val )
            {
                return isSameTree(p -> left,q -> left) && isSameTree(p -> right,q -> right);
            }
            else
            {
                return false;
            }
        }  
        return true;
    }
};

int main()
{
    return 0;
}