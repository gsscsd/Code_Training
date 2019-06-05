/**
题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 */

#include <iostream>
#include <vector>
using namespace std;


/**
 基本解决方法：
 1.设定奇偶两个指针，然后，奇数放前面，偶数放后面，没有做出来
 2.vector删除偶然然后在加入偶数
 3.构建一个新的数组，两次for循环，第一次加入奇数，第二次加入偶数
 */
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int size = array.size();
        int temp = 0;
        vector<int >::iterator it = array.begin();
        while(size)
        {
            if(!(*it % 2))
            {
                temp = *it;
                it = array.erase(it);
                array.push_back(temp);
            }
            else
            {
                it ++;
            }
            size --;
        }

    }
    void reOrderArray_0(vector<int> &array)
    {
        vector<int> temp;
        for(int i = 0;i < array.size();i++)
        {
            if(array[i] % 2 == 1)
            {
                temp.push_back(array[i]);
            }
        }
        for(int i = 0;i < array.size();i++)
        {
            if(array[i] % 2 == 0)
            {
                temp.push_back(array[i]);
            }
        }
        for(int i = 0;i < array.size();i++)
        {
            array[i] = temp[i];
        }
    }
};

int main()
{
    Solution s;
    vector<int> temp;
    for(int i = 0;i < 7;i++)
    {
        temp.push_back(i);
    }
    s.reOrderArray(temp);
    for(int i = 0;i < temp.size();i++)
    {
        cout << temp[i] << endl;
    }
    return 0;
}