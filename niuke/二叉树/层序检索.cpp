/**
题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。 
*/

/**
树的层序遍历
 */

#include <iostream>
#include <vector>
#include <queue>
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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode *> q_temp;
        TreeNode* temp;
        vector<int > vec;
        if(root == nullptr)
        {
            return vec;
        }
        else
        {
            q_temp.push(root);
            while(!q_temp.empty())
            {
                temp = q_temp.front();q_temp.pop();
                vec.push_back(temp->val);
                if(temp -> left != NULL) q_temp.push(temp -> left);      
                if(temp -> right != NULL) q_temp.push(temp -> right);
            }
        }
        return vec;
    }
};



int main()
{

}