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
设定一个栈对数据压栈，并且递归的处理
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
            
        }
};

int main()
{
    return 0;
}