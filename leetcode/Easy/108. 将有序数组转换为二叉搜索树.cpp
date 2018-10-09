/**
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:
给定有序数组: [-10,-3,0,5,9],
一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
      0
     / \
   -3   9
   /   /
 -10  5
*/

/**
解题思路：

*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){}
};


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        TreeNode *root = NULL;
        int high = nums.size();
        root = sortToBst(nums,0,high - 1);
        return root;        
    }

    // 采用分治算法，对于C++而言，传入下标比复制一遍数组有用的多
    TreeNode* sortToBst(vector<int>& num,int low,int high)
    {
        // 注意这里的边界判断
        if(low > high)
            return NULL;
        int mid = (low + high) / 2;
        TreeNode *t = new TreeNode(num[mid]);
        t -> left = sortToBst(num,low , mid - 1);
        t -> right = sortToBst(num,mid + 1, high);
        return t;
        // 注意以下失败的代码,思路是通过复制left和right的数组，结果内存泄漏
        // TreeNode *t = new TreeNode(num[mid]);
        // vector<int> left(num.begin(),num.begin() + mid - 1);
        // vector<int > right(num.begin() + mid + 1,num.end());
        // if(mid == 0) t->left = NULL;
        // else t->left = sortToBst(left);
        // t -> right = sortToBst(right);
        // return t;

    }
};

int main()
{
    return 0;
}


