/**
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
解题思路
这里的方法不需要记录已经走过的路径，所以执行用时和内存消耗都相对较小

1.首先设定上下左右边界
2.其次向右移动到最右，此时第一行因为已经使用过了，可以将其从图中删去，体现在代码中就是重新定义上边界
3.判断若重新定义后，上下边界交错，表明螺旋矩阵遍历结束，跳出循环，返回答案
4.若上下边界不交错，则遍历还未结束，接着向下向左向上移动，操作过程与第一，二步同理
5.不断循环以上步骤，直到某两条边界交错，跳出循环，返回答案
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        if (matrix.empty())
            return ans; //若数组为空，直接返回答案
        // 设置上下左右四个边界
        int top = 0;      //赋值上下左右边界
        int down = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while (true)
        {
            for (int i = l; i <= r; ++i)
                ans.push_back(matrix[top][i]); //向右移动直到最右
            if (++top > down)
                break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            for (int i = top; i <= down; ++i)
                ans.push_back(matrix[i][r]); //向下
            if (--r < l)
                break; //重新设定有边界
            for (int i = r; i >= l; --i)
                ans.push_back(matrix[down][i]); //向左
            if (--down < top)
                break; //重新设定下边界
            for (int i = down; i >= top; --i)
                ans.push_back(matrix[i][l]); //向上
            if (++l > r)
                break; //重新设定左边界
        }
        return ans;
    }
};
