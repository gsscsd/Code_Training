/**

翻转一棵二叉树。
发
示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

/**
解题思路：
递归来处理
*/

#include <iostream>
#include <vector>
#include <queue>

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
        // 没有写出来
        // 自己没有写出来，太菜了，明明不难的
        // 以下是递归的方法
        TreeNode* invertTree(TreeNode* root) 
        {
            if (!root) return nullptr;
            // 交换两个指针，是交换指针而不是值
            auto *pTmp = root->left;
            root->left = root->right;
            root->right = pTmp;
            // 递归的计算左子树
            invertTree(root->left);
            // 递归的计算右子树
            invertTree(root->right);
            
            return root;
        }
        // 非递归的方法需要用其他结构，比如栈，队列
        // 下面的这个代码，非递归的版本比较难，并且时空复杂度也比较高
        TreeNode *invertTree_(TreeNode* root)
        {
            // 使用两个队列
            queue<TreeNode*> q1, q2;
            if(root) q1.push(root);        
            while (!q1.empty()) {
                while (!q1.empty()) {
                    // 交换节点的指针,pTmp做中介
                    auto *pNode = q1.front(), *pTmp = pNode->left;
                    pNode->left = pNode->right;
                    pNode->right = pTmp;
                    if (pNode->left) q2.push(pNode->left);
                    if (pNode->right) q2.push(pNode->right);
                    q1.pop();
                }
                while (!q2.empty()) {
                    q1.push(q2.front());
                    q2.pop();
                }
            }
            
            return root;
        }
};



int main(int argc, char const *argv[])
{
    return 0;
}
