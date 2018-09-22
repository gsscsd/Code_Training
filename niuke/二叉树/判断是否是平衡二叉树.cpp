/**
题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/


/**
解题思路：
1.递归计算左右子树的高度，然后计算,但是这样有问题，会多次重复计算某些中间节点
2.从下往上遍历
*/


#include <iostream>
// #include <cmath>
#include <algorithm>

using namespace std;


typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
}TreeNode;

class Solution {
public:

    // 1.第一种方法，计算树的深度并且对比计算
    int getTreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL)
        {
            return 0;
        }
        else
        {
            return max(getTreeDepth(pRoot -> left),getTreeDepth(pRoot -> right)) + 1; 
        }
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(pRoot == NULL)
        {
            return true;
        }
        else
        {
            int left = getTreeDepth(pRoot -> left);
            int right = getTreeDepth(pRoot -> right);
            if(abs(left - right) > 1)
            {
                return false;
            }
            else
            {
                return IsBalanced_Solution(pRoot -> left) && IsBalanced_Solution(pRoot -> right);
            }
        }
    }
    // 以下是大神的优化的答案
    // 在getDepth函数这里
    int getDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int left = getDepth(root -> left);
        // 直接来判断是不是是平衡树
        if(left == -1) return -1;
        int right = getDepth(root -> right);
        if(right == -1) return -1;
        return abs(left - right) > 1 ? -1 : max(getDepth(root -> left),getDepth(root -> right)) + 1;
    }
    // 大神的主函数调用
    bool IsBalanced_Solution_(TreeNode* pRoot) {
        return getDepth(pRoot) != -1;
    }
};


int main()
{
    return 0;
}