/**
题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
 * 
 */

/**
解题思路：

已知条件：后序序列最后一个值为root；二叉搜索树左子树值都比root小，右子树值都比root大。
1、确定root；
2、遍历序列（除去root结点），找到第一个大于root的位置，则该位置左边为左子树，右边为右子树；
3、遍历右子树，若发现有小于root的值，则直接返回false；
4、分别判断左子树和右子树是否仍是二叉搜索树（即递归步骤1、2、3）。
1.递归
2.非递归
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    // 递归调用计算
    bool judge(vector<int>& a,int start,int end){
        // 这个边界条件不太懂
        // 最有可能的是start==end，此时只有一个数
        if(start >= end){
            return true;
        }
        int i = start;
        // 去找到根节点的位置
        while(a[i] < a[end]){
            ++i;
        }
        // 判断右子树是否存在比根节点还小的数
        for(int j = i;j < end;j++){
            if(a[j] < a[end]){
                return false;
            }
        }
        // 判断左边和右边
        return judge(a,start,i-1) && judge(a,i,end-1);
    }
    // 调用递归函数
    bool VerifySquenceOfBST(vector<int> sequence) {
         if(!sequence.size()) return false;
        return judge(sequence, 0, sequence.size() - 1);
    }
    // 非递归版本,想法很独特，看不太明白
    //非递归也是一个基于递归的思想：
    //左子树一定比右子树小，因此去掉根后，数字分为left，right两部分，right部分的
    //最后一个数字是右子树的根他也比左子树所有值大，因此我们可以每次只看有子树是否符合条件
    //即可，即使到达了左子树左子树也可以看出由左右子树组成的树还想右子树那样处理
    
    //对于左子树回到了原问题，对于右子树，左子树的所有值都比右子树的根小可以暂时把他看出右子树的左子树
    //只需看看右子树的右子树是否符合要求即可
    bool VerifySquenceOfBSt_(vector<int> sequence)
    {
        int size = sequence.size();
        if(0 == size) return false;

        int i = 0;
        while(--size)
        {
            while(sequence[i]<sequence[size]) i++;
            while(sequence[i]>sequence[size]) i++;

            if(i<size)return false;
            i=0;
        }
        return true;
    }


};

int main()
{
    vector<int> vec;
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(5);
    vec.push_back(8);
    vec.push_back(10);
    vec.push_back(13);
    vec.push_back(12);
    vec.push_back(9);
    Solution s;
    bool t;
    t = s.VerifySquenceOfBST(vec);
    cout << t << endl;
}
