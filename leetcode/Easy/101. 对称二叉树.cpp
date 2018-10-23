/**
给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
    1
   / \
  2   2
   \   \
   3    3
*/

/**
解题思路：
剑指offer的原题
递归处理 
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        if(!root) return true;
        return isSymmetric_(root -> left, root -> right);
    }
    bool isSymmetric_(TreeNode *left,TreeNode *right)
    {
        if(!left && !right) return true;
        if(!left || !right) return false;
        if(left -> val != right -> val) return false;
        // 如果上述的情况都不满足，此时就需要去判断，左子树的左子树与右子树的右子树以及，左子树的右子树与右子树的左子树
        return isSymmetric_(left -> left,right -> right) && isSymmetric_(left -> right,right -> left);
    }
    // leetcode 的非递归的答案
    bool isSymmetric_0(TreeNode* root) {
        if (!root)
            return true;
        TreeNode *p = root->left, *q = root->right;
        stack<TreeNode*> s;
        s.push(p);
        s.push(q);
        while (!s.empty()) {
            p = s.top();
            s.pop();
            q = s.top();
            s.pop();
            if (!p && !q)
                continue;
            if (!p || !q)
                return false;
            if (p->val != q->val)
                return false;
            s.push(p->left);
            s.push(q->right);
            s.push(p->right);
            s.push(q->left);
        }
        return true;
    }
};

int main()
{
    return 0;
}



