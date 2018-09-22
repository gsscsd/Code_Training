/**
题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5

*/
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};



class Solution {
public:
    void Mirror(TreeNode *pRoot) {

        if(pRoot == NULL)
        {
            return ;
        }
        else
        {
            // 交换左右子树
            TreeNode *pTemp = pRoot -> left;
            pRoot -> left = pRoot -> right;
            pRoot -> right = pTemp;
            // 递归交换左子树和右子树
            Mirror(pRoot -> left);
            Mirror(pRoot -> right);
        }     
    }
};
int main(int argc, char const *argv[])
{
    
    return 0;
}
