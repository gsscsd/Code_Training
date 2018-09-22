/**
题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
解题思路：
1、首先设置标志位result = false，因为一旦匹配成功result就设为true，
剩下的代码不会执行，如果匹配不成功，默认返回false
2、递归思想，如果根节点相同则递归调用DoesTree1HaveTree2（），
如果根节点不相同，则判断tree1的左子树和tree2是否相同，
再判断右子树和tree2是否相同
3、注意null的条件，HasSubTree中，如果两棵树都不为空才进行判断，
DoesTree1HasTree2中，如果Tree2为空，则说明第二棵树遍历完了，即匹配成功，
tree1为空有两种情况（1）如果tree1为空&&tree2不为空说明不匹配，
（2）如果tree1为空，tree2为空，说明匹配。
 */

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
}TreeNode;

class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        //当Tree1和Tree2都不为零的时候，才进行比较。否则直接返回false
        if(pRoot1 != NULL && pRoot2 != NULL)
        {

            if(pRoot1 -> val == pRoot2 -> val)
            {
                //以这个根节点为为起点判断是否包含Tree2
                result = DoesTree1HaveTree2(pRoot1,pRoot2);
            }
            // 如果，还是不匹配，计算左子树
            if(!result) {result = DoesTree1HaveTree2(pRoot1 -> left,pRoot2);}
            // 如果，还是不匹配，计算右子树
            if(!result) {result = DoesTree1HaveTree2(pRoot1 -> right,pRoot2);}
        }
        return result;
    }
    bool DoesTree1HaveTree2(TreeNode *pRoot1,TreeNode *pRoot2)
    {
        //如果Tree2还没有遍历完，Tree1却遍历完了。返回false
        if(pRoot1 == NULL && pRoot2 != NULL) return false;
        //如果Tree2已经遍历完了都能对应的上，返回true
        if(pRoot2 == NULL) return true;
        //如果其中有一个点没有对应上，返回false
        if(pRoot1 -> val != pRoot2 -> val) return false;
        // 否则，递归计算
        else
        {
            return DoesTree1HaveTree2(pRoot1 -> left,pRoot2 -> left) && DoesTree1HaveTree2(pRoot1 -> right,pRoot2 -> right);
        }
    }
};

int main()
{

}