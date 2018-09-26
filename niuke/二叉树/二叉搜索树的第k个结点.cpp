/**
题目描述
给定一棵二叉搜索树，请找出其中的第k小的结点。
例如,（5，3，7，2，4，6，8）中，按结点数值大小顺序第三小结点的值为4。
*/

/**
解题思路：
1.中序遍历存入到数组中，然后直接访问,未实现
2.定义一个全局索引，中序遍历，如果索引==k，就返回节点
*/


#include <iostream>
#include <string>
#include <vector>
#include <queue>
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
        // 1.第一种解法
        //中序遍历的结果就是有序序列，第K个元素就是vec[K-1]存储的节点指针；
        void TraversNode(TreeNode *pRoot,vector<TreeNode* > &vec)
        {
            if(pRoot == NULL) return;
            TraversNode(pRoot -> left ,vec);
            vec.push_back(pRoot);
            TraversNode(pRoot -> right ,vec);
        }

        TreeNode* KthNode_(TreeNode* pRoot, int k)
        {
                // 太坑了，第一次写的时候，此处的边界条件没有判断，所以，直接报错了
                if(pRoot == NULL||k <= 0) return NULL;
                vector<TreeNode*> v;
                TraversNode(pRoot,v);
                if(k > v.size())
                    return NULL;
                return v[k - 1];
        }  
        // 2.中序遍历
        // 定义一个index,记录访问的节点的数目
        int index= 0;
        TreeNode* KthNode(TreeNode* pRoot, int k)
        {
                if(pRoot)
                {
                        TreeNode *node = KthNode(pRoot -> left,k);
                        if(node) return node;
                        // 每次访问一个节点就加1
                        ++index;
                        if(index == k) return pRoot;
                        node = KthNode(pRoot -> right,k);
                        if(node) return node;
                }
                return NULL;
        }  
};


int main()
{
        return 0;
}