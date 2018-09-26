/**
题目描述
请实现两个函数，分别用来序列化和反序列化二叉树
*/

/**

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
    char* Serialize(TreeNode *root) {    
        
    }
    TreeNode* Deserialize(char *str) {
    
    }
};
