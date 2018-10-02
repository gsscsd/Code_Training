/**
题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/

/**
解题思路：
1.
核心思路：回溯法
1.先将matrix字符串映射为字符矩阵；
2.从原字符串中找到第一个跟str[0]相等的字符，得到其对应的在矩阵中的位置[r,c]
1）从[r,c]开始按 上、左、右、下的顺序搜索；
2）每当搜索到一个节点，先判断path是否包括它，包括就说明已经经过此节点，不能
再经过了；如果不包括，就将其加入path容器
3）直到搜索到str[length - 1]节点，说明成功找到，标记result为true，标记
isFinished为true,尽快结束所有的递归操作
4）如果某节点起的 上、左、右、下 都搜索过但还没找到结果，说明经过此节点的路
径都不满足题意，将其从path中删除，回溯到上一层继续找。
（PS:确实是回溯法，不过代码有点长，实现的有点繁杂）
2.bool数组递归查询，代码没有看懂呢
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>


using namespace std;

class Solution {
public:
        bool hasPath(char* matrix, int rows, int cols, char* str)
        {
                int m_len = strlen(matrix);
                int s_len = strlen(str);
                // 定义一个数组
                int *flag = new int[m_len]();
                // 初始化
                // memset(flag,0,sizeof(flag));
                for(int i = 0; i < rows;i++)
                {
                        for(int j = 0; j < cols;j++)
                        {
                                if(searchFromHere(matrix,rows,cols,i,j,str,0,flag))
                                {
                                        return true;
                                }
                        }
                }
                return false；
        }
        // 注意参数说明
        // 这里的代码没有看懂呢，参数k代表了访问str的第几个字符了
        // 代码的思路好清晰，但是注意的是代码的边界是如何的处理
        bool searchFromHere(char *matrix,int rows,int cols,int i,int j,char *str,int k,int *flag)
        {
                // 索引
                int index = i * cols + j;
                // 边界判断，如果超出边界或者字符不想等或者访问过这个字符
                if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || flag[index] == 1)
                        return false;
                // 如果访问到str的尾部
                if(k == strlen(str) - 1) return true;
                // 标记当前字符被访问,然后从这个方向向下访问
                flag[index] = 1;
                // 搜索其他方向的字符是否匹配，递归处理
                if (searchFromHere(matrix, rows, cols, i - 1, j, str, k + 1, flag)
                        || searchFromHere(matrix, rows, cols, i + 1, j, str, k + 1, flag)
                        || searchFromHere(matrix, rows, cols, i, j - 1, str, k + 1, flag)
                        || searchFromHere(matrix, rows, cols, i, j + 1, str, k + 1, flag)) 
                {
                        return true;
                }
                // 条件不符合，还原为未访问过的标记
                flag[index] = 0;
                return false;
        }
};


int main()
{
        return 0;
}




