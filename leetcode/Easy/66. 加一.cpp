/**
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:
输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。

示例 2:
输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。 
*/

/**
解题思路：
1.遍历查找类似于合并链表
*/

#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    // 自己写的代码，好冗余，但是通过了
    // 屎一样的代码，冗余且难以懂
    vector<int> plusOne(vector<int>& digits) {

        // flag判断是否进位哦
        bool flag = false;
        vector<int > vec;
        int len = digits.size();
        int temp = 0;
        for(int i = len - 1 ;i >= 0;--i)
        {
            // 如果是最后一个数字，直接加1 
            if(i == len - 1) temp = digits[i] + 1;
            // 如果进位并且不是最后一位，那么加1
            else if(flag && i != len - 1) temp = digits[i] + 1;
            // 否则当前位就是这个数字
            else temp = digits[i];
            // 如果当前数字大于等于10，那就要进位了
            if(temp == 10)
            {
                flag = true;
                temp = 0;
            }
            else
            {
                flag = false;
            }
            // 当前位的数字赋值
            digits[i] = temp;
        }
        // 如果进位，在最前面插入1
        if(flag) digits.insert(digits.begin(),1);
        return digits;    
    }
    // leetcode 高效率答案，总是这么简洁有效
    vector<int> plusOne_(vector<int>& r) {

        for (int i = r.size() - 1; i >= 0; i--) {
            r[i] += 1;
            // 关键是这里的处理，如果当前的数大于10，那么就应该存储0，同时下一个元素加1
            if (r[i] == 10) {
                r[i] = 0;
            }
            // 如果，当前的元素没有等于10，那么直接返回就可以了
            else 
            {
                return r;
            }
        }
        // 如果没有返回数据，说明还有进位，此时插入1
        r.insert(r.begin(), 1);
        return r;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vector<int> temp = s.plusOne(vec);
    for(auto v : temp)
    {
        cout << "v is " << v << endl;
    }
    
    return 0;
}
