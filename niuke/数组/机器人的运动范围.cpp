/**
题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），
因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？ 
*/


/**
解题思路：
牛客网的高票答案
核心思路：
1.从(0,0)开始走，每成功走一步标记当前位置为true,然后从当前位置往四个方向探索，
返回1 + 4 个方向的探索值之和。
2.探索时，判断当前节点是否可达的标准为：
1）当前节点在矩阵内；
2）当前节点未被访问过；
3）当前节点满足limit限制。
// 注意他的分析思路
比如说，节点是否可以访问，用函数来处理，位置数值的分解用函数来处理

*/

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Solution {
public:
        // 回溯法，其实套路都是一样的
        int movingCount(int threshold, int rows, int cols)
        {
                // 设定一个二维的bool数组，标记是否被访问
                // vector<vector<bool> >flag(rows,vector<bool>(cols,false));
                // 其实设定一个一维数组也可以
                bool *flag = new bool[rows * cols]();
                // 从0，0进入开始访问
                int count = move(threshold,rows,cols,0,0,flag);
                return count;

        }
        // 递归的去处理他
        int move(int threshold,int rows,int cols,int i,int j,bool *flag)
        {
                int count = 0;
                // 如果当前节点可以被访问
                if(check(threshold,rows,cols,i,j,flag))
                {
                        flag[i * cols + j] = true;
                        //标记访问过，这个标志flag不需要回溯，因为只要被访问过即可。
                        //因为如果能访问，访问过会加1.不能访问，也会标记下访问过。
                        // count 等于当前节点的值加1，然后再去加上四个方向的值
                        count = 1+move(threshold,rows,cols,i-1,j,flag)
                                +move(threshold,rows,cols,i,j-1,flag)
                                +move(threshold,rows,cols,i+1,j,flag)
                                +move(threshold,rows,cols,i,j+1,flag);
                }
                return count;

        }
        //检查当前位置是否可以访问
        bool check(int threshold,int rows,int cols,int i,int j,bool *flag)
        {
                if( i>=0 && i< rows && j>=0 && j<cols
                        && getSum(i) + getSum(j)<=threshold
                        && flag[i*cols+j] == false)
                        return true;
                return false;
        }
        //计算位置的数值
        int getSum(int number)
        {
        int sum=0;
        while(number > 0)
        {
                sum+=number%10;
                number/=10;
        }
        return sum;
        }
};


int main(int argc, char const *argv[])
{
        return 0;
}





