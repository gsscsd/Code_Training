/**
题目描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，
但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 
例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
*/

/**
解题思路：
1.设定map来做,空间复杂度比较高
2.设定一个boolean数组，空间复杂度依然比较高
3.牛客高分答案，通过给定的信息，空间复杂度O（1）,但是会出现溢出问题

题目里写了数组里数字的范围保证在0 ~ n-1 之间，
所以可以利用现有数组设置标志，当一个数字被访问过后，可以设置对应位上的数 + n，
之后再遇到相同的数时，会发现对应位上的数已经大于等于n了，那么直接返回这个数即可。
*/


#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std;

class Solution {
public:
    // 牛客的高分答案,时间O(n),空间O(1)
    bool duplicate(int numbers[], int length, int* duplication) {
        for(int i = 0;i < length;++i)
        {
            // 首先找到numbers的值
            int index = numbers[i];
            // 注意这里的边界条件
            if(index >= length)
            {
                index -= length;
            }
            // cout << "index " << index << " number " << numbers[index] << endl;
            // 如果numbers对应的index长度比length大，那么说明就找到了
            if(numbers[index] >= length)
            {
                // 赋值并返回
                duplication[0] = index;
                // break;
                return true;
            }
            // 将对应的下标加上长度
            numbers[index] += length;
        }
        return false;   
    }

    bool duplicate_(int numbers[],int length,int *duplication)
    {
        bool *flag = new bool[length]();
        // int flag[] = new int[length](0);
        for(int i = 0;i < length ;++i)
        {
            if(flag[numbers[i]] == true)
            {
                *duplication = numbers[i];
                return true;
            }
            flag[numbers[i]] = true;
        }
        return false;   
    }
};

int main()
{
    Solution s;
    int numbers[] = {2,1,3,0};
    int length = 4;
    int dup = 0;
    s.duplicate_(numbers,length,&dup);
    cout << "the last is " << dup << endl;
    return 0;
}

