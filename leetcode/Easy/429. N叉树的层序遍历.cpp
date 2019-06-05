/**
给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。
*/

/**
解题思路:
非递归的层次遍历
*/

#include <vector>
#include <iostream>
#include <queue>


using namespace std;

class Node 
{
    public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val, vector<Node*> _children) 
        {
            val = _val;
            children = _children;
    }
};


class Solution 
{
    public:
        vector<vector<int> > levelOrder(Node* root) 
        {
            vector<vector<int> > res;
            if(!root) return res;
            queue<Node *> q;
            q.push(root);
            while(!q.empty())
            {
                vector<int> v;
                int s_z = q.size();
                for(int i = 0;i < s_z;i++)
                {
                    
                    Node *t = q.front();q.pop();
                    v.push_back(t -> val);
                    for(auto a : t -> children)
                    {
                        if(a) q.push(a);
                    }
                }
                res.push_back(v);
                v.clear();
            }
            return res;
        }
};

//  大神的递归的做法
class Solution_ {
public:
    void levelOrder_(Node* root,int level,vector<vector<int> > &rs){
        if(root == NULL) return;
        if(level == rs.size()){
            rs.push_back({});
        }
        rs[level].push_back(root->val);
        for (Node *node : root->children) {
            levelOrder_(node,level + 1,rs);
        }
    }

    vector<vector<int> > levelOrder(Node* root) {
        vector<vector<int> > rs;
        levelOrder_(root, 0, rs);
        return rs;
    }
};