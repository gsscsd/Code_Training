/**
题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/

/**
解题思路
1.中序遍历压栈处理：然后弹出栈来修改指针
**/
#include <iostream>
#include <vector>
#include <stack>


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
    // 1.中序遍历的非递归版本
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        stack<TreeNode *> p_stack;

        if(pRootOfTree == NULL)
        {
            return NULL;
        }
        Traversal(pRootOfTree,p_stack);
        // 还有非递归的版本
        TreeNode* ptemp = p_stack.top();
        p_stack.pop();
        while(!p_stack.empty())
        {
            TreeNode *temp = p_stack.top();
            p_stack.pop();
            ptemp -> left = temp;
            temp -> right = ptemp;
            ptemp = temp;
        }
        return ptemp;

    }
    // 2.中序遍历的递归版本，比较重要记住
    void Traversal(TreeNode* pRoot,stack<TreeNode* > &p_stack)
    {
        if(pRoot)
        {
            // 访问左子树
            Traversal(pRoot -> left,p_stack);
            // 加入到栈
            p_stack.push(pRoot);
            // 访问右子树
            Traversal(pRoot -> right,p_stack);
        }
    }

    // 3.高分答案的另一种递归计算

    TreeNode* Convert_(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == nullptr) return nullptr;
        TreeNode* pre = nullptr;
        
        convertHelper(pRootOfTree, pre);
        
        TreeNode* res = pRootOfTree;
        while(res ->left)
            res = res ->left;
        return res;
    }
        
    void convertHelper(TreeNode* cur, TreeNode*& pre)
    {
        if(cur == nullptr) return;
        
        convertHelper(cur ->left, pre);
        
        cur ->left = pre;
        if(pre) pre ->right = cur;
        pre = cur;
        
        convertHelper(cur ->right, pre);
        
    }
};


int main()
{

}