/**
题目描述
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)
 */

/**
解题思路：
1. DFS的变体

2. 非递归法：后序遍历
    1.进栈时候，把值同时压入路径的向量数组，修正路径的和
    2.出栈时候，先判断和是否相等，且该节点是否是叶节点，
    判断完成后保持和栈一致，抛出路径，修改路径的和
    3.向量数组和栈的操作要保持一致
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
    // 先定义
    vector<vector<int> > listall;
    vector<int > list;
    // 递归遍历来计算
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == NULL)
        {
            return listall;
        }
        // list加入节点
        list.push_back(root -> val);
        // 每次减去这个节点的值
        expectNumber -= root -> val;
        // 如果值相等，并且是叶子节点
        if(expectNumber == 0 && root -> left == NULL && root -> right == NULL)
        {
            // 将lsit这个路径加入到path里面，要根据list重新new一个vector对象，否则，永远指向一个位置的节点
            listall.push_back(vector<int>(list));
        }
        FindPath(root -> left, expectNumber);
        FindPath(root -> right, expectNumber);
        // 回退到上一节点,这个是比较重要的操作
        list.pop_back();
        return listall;
    }

    // 另一种标准的DFS遍历方式

    vector<vector<int> > FindPath_(TreeNode* root,int expectNumber) {
        vector<vector<int> > ret;
        vector<int> trace;
        if(root)
            dfs(root,expectNumber,ret,trace);
        return ret;
    }
    void dfs(TreeNode* root,int s,vector<vector<int> > &ret,vector<int> &trace) {
        // 节点先入栈，
        trace.push_back(root->val);
        // 这里是边界条件的判断
        if(!root->left&&!root->right) {
            if(s == root->val)
                ret.push_back(trace);
        }
        // 左子树的遍历
        if(root->left)
            dfs(root->left,s - root->val,ret,trace);
        // 右子树的遍历
        if(root->right)
            dfs(root->right,s - root->val,ret,trace);
        // 回退，弹出节点
        trace.pop_back();
    }

};



int main()
{
    return 0;
}