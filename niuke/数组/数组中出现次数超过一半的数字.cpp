/**
题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。 
 */

/***
解题思路
1.将数据存入到字典中，value是频率 效率还是不太高
2.小象学院的做法，时间O(n)，空间O(1)
解题：定义一个m和c，m是候选的众数，c代表次数，
每次判断m与A[i]是否相同，如果不相同就同时删除
 **/

#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:

    int MoreThanHalfNum_Solution(vector<int> numbers) 
    {
        map<int,int> dict;
        for(int i = 0;i < numbers.size();i++)
        {
            if(!dict.count(numbers[i]))
            {
                dict[numbers[i]] = 1;
            }
            else
            {
                dict[numbers[i]] += 1;
            }
        }
        int half_size = numbers.size() / 2;
        int result = 0;
        map<int,int>::iterator itor = dict.begin();
        for(;itor != dict.end();itor++)
        {
            cout << "first is " << itor -> first << " second is " << itor -> second << endl;
            if(itor -> second > half_size)
            {
                result = itor -> first;
            }
        }
        return result;    
    }

    // 注意以下代码参考自小象学院数组那一章节
    // 恩，自己还是默写不出来，太菜
    int MoreThanHalfNum_Solution_(vector<int> numbers)
    {
        int count = 0;
        int m = numbers[0];
        for(int i = 0; i < numbers.size();i++)
        {
                if(count == 0)
                {
                        m = numbers[i];
                        count = 1;
                }
                else if (m != numbers[i])
                {
                        count--;
                }
                else count++;
        }
        return m;
    }
};



int main()
{
    vector<int > vec;
    // 1,2,3,2,2,2,5,4,2
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(2);

    Solution s;

    int result = 0;
    result = s.MoreThanHalfNum_Solution(vec);
    cout << result << endl;

    return 0;
}

