/**
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。

示例:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
*/

/**
解题思路：
通过辅助stack来实现
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class MinStack 
{
    public :
        MinStack() 
        {
        
        }
        
        // 入栈元素
        void push(int x) 
        {
            if(st.empty() && min_st.empty())
            {
                st.push(x);
                min_st.push(x);
            }
            else 
            {
                st.push(x);
                if(min_st.top() > x) min_st.push(x);
            } 
        }
        
        // 出栈元素
        void pop() 
        {
            if(!st.empty() && !min_st.empty())
            {
                if(min_st.top() == st.top())
                {
                    min_st.pop();st.pop();
                }
                else st.pop();
            }
            
        }
        
        // 获取栈顶元素
        int top() 
        {
            return st.top();
        }
        
        // 获取最小元素
        int getMin() 
        {
            return min_st.top();  
        }
    private :
        stack<int> st;
        stack<int> min_st;
};


int main(int argc, char const *argv[])
{
    
    return 0;
}





