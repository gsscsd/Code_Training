/**
题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
*/

/**
解题思路：
根据题目可以考虑到采用BFS
层序遍历
*/


#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > vec;
        // 定义一个队列，变体
        queue<TreeNode *> q;
        if(pRoot == NULL ) return vec;
        q.push(pRoot);
        // 添加一层奇偶的判断
        bool even = false;
        while(!q.empty())
        {
                // 计算队列的长度，只访问当前一层的数据
                int q_size = q.size();
                vector<int> v;
                for(int i = 0; i < q_size;i++)
                {
                        TreeNode *t = q.front();
                        q.pop();
                        // 添加数组
                        v.push_back(t -> val);
                        // 接着存入下一层的节点
                        if(t -> left != NULL) q.push(t -> left);
                        if(t -> right != NULL) q.push(t -> right);
                }
                if(even)
                {
                        // 说明一下，此处的代码，海量数据时效率根本就不行
                        reverse(v.begin(),v.end());
                }
                // 方向变换
                even = !even;
                vec.push_back(v);
        }
        return vec;
    }
    
};
// 牛客网的比较高效率的答案，通过两个数组来进行保存数据
class Solution_ {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (pRoot == NULL)
            return res;
        vector<TreeNode*> q1;
        vector<TreeNode*> q2;
        q1.push_back(pRoot);
        bool model = true;//ture表示方向从左向右
        while (!q1.empty()){
            q2 = q1;
            q1.clear();
            vector<int> row;
            while (!q2.empty()){//把当前层全部访问，并将孩子按一定顺序入栈
                TreeNode *temp = q2.back();
                q2.pop_back();
                row.push_back(temp->val);
                if (model == true){//ture为从左向右
                    if (temp->left) q1.push_back(temp->left);
                    if (temp->right) q1.push_back(temp->right);
                }
                else{//false为从右向左
                    if (temp->right) q1.push_back(temp->right);
                    if (temp->left) q1.push_back(temp->left);
                }
            }
            model = !model;//变换方向
            res.push_back(row);
        }
        return res;
    }
};


int main()
{
        return 0;
}


