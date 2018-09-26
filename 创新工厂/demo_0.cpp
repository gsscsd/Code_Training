/**
输入N个整数，先后顺序从1-N编号。每次删掉奇数位置上的数，
并将剩下的数按输入的先后顺序重新组成一个新的数列，重复执行以上两个操作，
直到数列中只剩下一个数，此数名为幸运数，则输出该幸运数的值及其所在输入序列的位置。

样例输入
5 
6 66 666 6666 66666
样例输出
6666
4

*/

/**
解题思路：
1.递归计算 82%
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>


using namespace std;

int luck_num(vector<int> &vecs)
{
    int len = vecs.size();
    if(len == 1) return vecs[0];
    vector<int> num;
    for(int i = 0;i < len;i++)
    {
        if((i + 1) % 2 == 0)
        {
            num.push_back(vecs[i]);
        }
    }
    return luck_num(num);   
}

int main()
{
    int n = 0;
    cin >> n;
    vector<int> vec;
    for(int i = 0 ;i < n;i++)
    {
        int temp = 0;
        cin >> temp;
        vec.push_back(temp);
    }
    int aim = luck_num(vec);
    int index = -1;
    for(int i = 0 ;i < n;i++)
    {
            if(vec[i] == aim)
            {
                    index = i + 1;
                    break;
            }
    }
    cout << aim << endl;
    cout << index << endl;
    return 0;
}