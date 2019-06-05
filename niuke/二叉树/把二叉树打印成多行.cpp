/**
题目描述
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。 
*/

/**
解题思路：
BFS
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
        vector<vector<int> > Print(TreeNode* pRoot) {
                vector<vector<int> > vec;
                queue<TreeNode *> q;
                if(pRoot == NULL) return vec;
                q.push(pRoot);
                while(!q.empty())
                {
                        int len = q.size();
                        vector<int> v;
                        for(int i = 0; i < len;i++)
                        {
                                TreeNode *t = q.front();
                                q.pop();
                                v.push_back(t -> val);
                                if(t -> left != NULL) q.push(t -> left);
                                if(t -> right != NULL) q.push(t -> right);
                        }
                        vec.push_back(v);
                }
                return vec;
        }
    
};
 

int main(int argc, char const *argv[])
{
        
        return 0;
}
 
