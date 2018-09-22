/*
题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 解决思路
// 入栈：将元素进队列A
// 出栈：判断队列A中元素的个数是否为1，如果等于1，则出队列，否则将队列A中的元素   
// 以此出队列并放入队列B，直到队列A中的元素留下一个，然后队列A出队列，
// 再把队列B中的元素出队列以此放入队列A中。

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int a = stack2.top();
        stack2.pop();
        return a;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(int argc, char const *argv[])
{
    /* code */

    Solution s;
    
    for(int i = 0;i < 3;i++)
    {
        cout << "push " << i << endl;
        s.push(i);
    }
    cout << s.pop() << " " << s.pop() << " "<< s.pop() << " " <<endl;

    return 0;
}




