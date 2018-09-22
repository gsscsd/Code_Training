/**
题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。 
 */

/***
解题思路
1.将数据存入到字典中，value是频率
 **/

#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:

    int MoreThanHalfNum_Solution(vector<int> numbers) {
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

