// 题目描述
// 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
// 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
// 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。

#include <iostream>
#include <string>
using namespace std;


typedef struct TreeNode {
    int val;
    TreeNode  left;
    TreeNode  right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

// 解题方法：
// 从前序数组找到根节点，然后从中序数组找到左右孩子节点，递归的处理
/* 先序遍历第一个位置肯定是根节点node，
 
  中序遍历的根节点位置在中间p，在p左边的肯定是node的左子树的中序数组，p右边的肯定是node的右子树的中序数组
 
  另一方面，先序遍历的第二个位置到p，也是node左子树的先序子数组，剩下p右边的就是node的右子树的先序子数组
 
  把四个数组找出来，分左右递归调用即可
 
*/

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int in_size = vin.size();
        // 这里也是一个递归的结果，如果数组长度为0，则说明是叶子节点；
        if(in_size == 0) return NULL;
        int gen = 0;
        int root = 0;
        // 首先找到根节点
        root = pre[0];
        // 构建四个vector用来保存根据根节点切分的前序和中序的左右孩子数组
        vector<int> pre_left,pre_right,vin_left,vin_right;
        for(int i = 0;i < in_size;i++)
        {
            if(vin[i] == root)
            {
                gen = i;
                break;
            }
        }
        TreeNode *proot = new TreeNode(root);
        for(int i = 0;i < in_size;i++)
        {
            
            if(i < gen)
            {
                // 这里需要注意一下，pre数组需要加1，是因为它应该从第二个开始；
                pre_left.push_back(pre[i + 1]);
                vin_left.push_back(vin[i]);
            }
            else if(i > gen)
            {
                pre_right.push_back(pre[i]);
                vin_right.push_back(vin[i]);
            }
        }
        proot->left = reConstructBinaryTree(pre_left,vin_left);
        proot->right = reConstructBinaryTree(pre_right,vin_right);
        return proot;
    }
};

int main(int argc,char argc[])
{
    
    return 0;
}





