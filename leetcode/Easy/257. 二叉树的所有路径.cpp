/**
给定一个二叉树，返回所有从根节点到叶子节点的路径。
说明: 叶子节点是指没有子节点的节点。

示例:
输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]
解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
*/

/**
解题思路：
广度优先遍历
设定一个数组来保存节点，前序遍历即可
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
        vector<string> binaryTreePaths(TreeNode* root) 
        {
            vector<string> res;
            if(!root) return res;
            vector<int> vec;
            help(root,res,vec);
            return res;
        }
        // 采用前序递归遍历
        // 其实代码上倒也都是一样的，不过效率低的原因在于每次去计算路径
        // 所以，可以优化的地方就是把路径当作参数，传入函数里面
        void help(TreeNode *root,vector<string> &res,vector<int>& vec)
        {
            vec.push_back(root -> val);
            string st = "";
            if(!root->left && !root -> right)
            {
                for(int i = 0; i < vec.size();i++)
                {
                    st += to_string(vec[i]);
                    if(i != vec.size() - 1)
                    {
                        st += "->";
                    }
                }
                res.push_back(st);
            }
            if(root -> left)
                help(root -> left,res,vec);
            if(root -> right)
                help(root -> right,res,vec);
            // 同时是否考虑将这个节点删除
            vec.pop_back();
        }
        // 下面根据大神的代码做优化，主要优化路径
        void help_0(TreeNode *root,vector<string> &res,string path)
        {
            if(!root) return ;
            if(!root -> left && !root -> right) res.push_back(path + to_string(root -> val));
            if(root -> left)
                help_0(root -> left,res,path  + to_string(root->val) + "->");
            if(root -> right)
                help_0(root -> right,res, path + to_string(root->val) + "->");
        }
};

// 大佬的代码，更加简洁
class Solution_0 {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        binaryTreePath(root, "", result);
        return result;
    }
    
    void binaryTreePath(TreeNode* root, string path, vector<string>& result)
    {
        if (!root)
        {
            return;
        }
        if (!root->left && !root->right)
        {
            result.push_back(path + to_string(root->val));
        }
        if (root->left)
        {
            binaryTreePath(root->left, path + to_string(root->val) + "->", result);
        }
        if (root->right)
        {
            binaryTreePath(root->right, path + to_string(root->val) + "->", result);
        }
    }
};

int main()
{
    return 0;
}