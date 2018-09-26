/**
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/

/**
解题思路：
递归处理
思路：首先根节点以及其左右子树，左子树的左子树和右子树的右子树相同
* 左子树的右子树和右子树的左子树相同即可，采用递归
* 非递归也可，采用栈或队列存取各级子树根节点
对称需要处理的是左子树的左子树与右子树的右子树相同，同时左子树的右子树和右子树的左子树相同
 
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


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
        // 递归处理
        bool comRoot(TreeNode *pLeft,TreeNode *pRight)
        {
                if(pLeft == NULL && pRight == NULL) return true;
                if(pLeft != NULL && pRight != NULL)
                {
                        // 这里的代码可以优化到短路算法
                        // if(pLeft -> val == pRight -> val) 
                        //         return comRoot(pLeft -> right,pRight -> left) && comRoot(pLeft -> left,pRight -> right);
                        // else 
                        // {
                        //         return false;
                        // }  
                        // 直接将数值的对方放到return里面去
                        return pLeft -> val == pRight -> val && comRoot(pLeft -> right,pRight -> left) && comRoot(pLeft -> left,pRight -> right);
                }
                // 这里要不要加else
                return false;
        }

        bool isSymmetrical(TreeNode* pRoot)
        {
                if(pRoot == NULL) return true;
                return comRoot(pRoot -> left,pRoot -> right);
        }

};


int main(int argc, char const *argv[])
{
        /* code */
        return 0;
}




