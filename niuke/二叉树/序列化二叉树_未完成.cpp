/**
 * 
 * 
 * 
*/


/**
解题思路：

1. 对于序列化：使用前序遍历，递归的将二叉树的值转化为字符，并且在每次二叉树的结点
不为空时，在转化val所得的字符之后添加一个' ， '作为分割。对于空节点则以 '#' 代替。
 2. 对于反序列化：按照前序顺序，递归的使用字符串中的字符创建一个二叉树(特别注意：
在递归时，递归函数的参数一定要是char ** ，这样才能保证每次递归后指向字符串的指针会
随着递归的进行而移动！！！
*/


#include <iostream>
#include <vector>
#include <string>


using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

/**

这是一道有毛病的题

typedef TreeNode* pnode;

class Solution {
    pnode hehe;
public:
    char* Serialize(TreeNode *root) {    
        hehe = root;
        return "(*^_^*)";
    }
    TreeNode* Deserialize(char *str) {
      return hehe;
    }
};

*/


class Solution {
public:

    char* Serialize(TreeNode *root) {    
        
    }

    TreeNode* Deserialize(char *str) {
    
    }

};



int main(int argc, char const *argv[])
{
        
        
        return 0;
}