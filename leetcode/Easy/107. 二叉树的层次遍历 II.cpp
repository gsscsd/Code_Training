/**
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
例如：
给定二叉树 [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：
[
  [15,7],
  [9,20],
  [3]
]
*/

/**
解题思路：
剑指offer
*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){}
};

class Solution{
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {

        vector<vector<int> > result;
        stack<vector<int> > st;
        if(!root) return result;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> temp;
            int size_ = q.size();
            for(int i = 0;i < size_;i++)
            {
                TreeNode* t = q.front();q.pop();
                temp.push_back(t -> val);
                if(t -> left) q.push(t -> left);
                if(t -> right) q.push(t -> right);
            }
            st.push(temp);
            temp.clear();
        }
        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};


int main()
{
    return 0;
}