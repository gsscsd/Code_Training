/**
题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/

/**
解题思路：
PS:说明一下，本程序中，中序二叉树已经构建完成了，是寻找后续节点，而不是去构建后续节点
1.二叉树为空，则返回空；
2.节点右孩子存在，则设置一个指针从该节点的右孩子出发，
一直沿着指向左子结点的指针找到的叶子节点即为下一个节点；
3.节点不是根节点。如果该节点是其父节点的左孩子，则返回父节点；
否则继续向上遍历其父节点的父节点，重复之前的判断，返回结果。
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};


class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL) return NULL;
        // 去找右子树的最左子树的叶节点
        if(pNode -> right != NULL)
        {
                // TreeLinkNode *pTemp = pNode -> right;
                pNode = pNode -> right;
                while(pNode -> left != NULL)
                {
                        pNode = pNode -> left;
                }
                return pNode;
        }
        // 如果它的后续节点不为空
        while(pNode -> next != NULL)
        {
                // 
                TreeLinkNode *pRoot = pNode -> next;
                // 没右子树，则找第一个当前节点是父节点左孩子的节点
                // 该节点不是根节点，若该节pRoot点是其父节点的左孩子，则返回父节点；
                // 否则继续向上遍历其父节点的父节点，重复之前的判断，返回结果。
                if(pRoot -> left == pNode)
                {
                        return pRoot;
                }
                // 一直去找本节点的父节点
                pNode = pNode -> next;
        }
        // 如果上述情况不满足，那么就返回NULL
        return NULL;   
    }
};


int main()
{
        return 0;
}




