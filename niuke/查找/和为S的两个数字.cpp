/**
题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。 
*/

/**
解题思路：
头尾指针，自己想到了，但是处理上有问题
数列递增有序的话，处理方式就是头尾指针
若ai + aj == sum，就是答案（相差越远乘积越小）
若ai + aj > sum，aj肯定不是答案之一（前面已得出 i 前面的数已是不可能），j -= 1
若ai + aj < sum，ai肯定不是答案之一（前面已得出 j 后面的数已是不可能），i += 1
*/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        
        int len = array.size();

        vector<int> vec;
        if(len < 2)
        {
            return vec;
        }
        // 定义两个头尾指针
        int head = 0;
        int tail = len - 1;

        // 定义两个中间变量
        int a0 = 0,a1 = 0;

        while(head < tail)
        {
            // cout << "head is " << head << " " << array[head] << " tail is " << tail << ' ' << array[tail] << endl;
            if(sum == (array[head] + array[tail]))
            {
                // a0 = array[head];
                // a1 = array[tail];
                vec.push_back(array[head]);
                vec.push_back(array[tail]);
                // 找到第一组就直接退出
                break;
            }
            // 否则的话，调节头尾指针
            while(head < tail && array[head] + array[tail] > sum) --tail;
            while(head < tail && array[head] + array[tail] < sum) ++head;
        }
        return vec;
    }
};

int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(11);
    vec.push_back(15);
    int k = 15;
    Solution s;
    vector<int> temp;
    temp = s.FindNumbersWithSum(vec,k);
    for(auto s:temp)
    {
        cout << s << endl;
    }


}