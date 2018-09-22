/**
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。 
 */

#include <iostream>
#include <stack>
using namespace std;

/**
解题思路：
思路：利用一个辅助栈来存放最小值
比如，data中依次入栈，5,  4,  3, 8, 10, 11, 12, 1
      则min依次入栈，5,  4,  3，no,no, no, no, 1
每入栈一次，就与辅助栈顶比较大小，如果小就入辅助栈，如果大就入当前栈
栈顶当出栈时，辅助栈也要出栈
这种做法可以保证辅助栈顶一定都当前栈的最小值 
*/

class Solution {
public:
    stack<int > min_;
    stack<int > data;
    int temp = NULL;
    void push(int value) {
        // 首先去判断temp不为空的时候
        if(temp != NULL)
        {
            // 如果当前数据比新的数据小
            if(value <= temp)
            {
                temp = value;
                min_.push(temp);
            }
            data.push(value);
        }
        else
        {
            temp = value;
            data.push(value);
            min_.push(value);
        }
    }
    void pop() {
        // 出栈
        int num_0 = data.top();data.pop();
        int num_1 = min_.top();min_.pop();
        // 两个栈同时弹出数据，随后计算栈顶元素是否相等，不相等就将
        // 辅助栈出来的数据重新压栈
        if(num_0 != num_1)
        {
            min_.push(num_1);
        }
        
    }
    int top() {
        int num = data.top();
        return num;
        
    }
    int min() {
        int num = min_.top();
        return num;  
    }
};


int main()
{

}