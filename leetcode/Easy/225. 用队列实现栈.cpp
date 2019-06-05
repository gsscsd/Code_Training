/**
使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空
注意:

你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
*/

/**
解题思路：
模拟运行
使用两个队列来做
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

class MyStack {
    public:
        /** Initialize your data structure here. */
        MyStack() 
        {
            
        }
        
        /** Push element x onto stack. */
        void push(int x) 
        {
            // 每次将元素加入到非空的队列里面
            if(!p.empty())
            {
                p.push(x);
            }
            else 
            {
                q.push(x);
            }
        }
        /** Removes the element on top of the stack and returns that element. */
        int pop() 
        {
            int temp = 0;
            if(!p.empty())
            {
                temp = p.front();
                while(temp != p.back())
                {
                    q.push(temp);
                    p.pop();
                    temp = p.front();   
                }
                p.pop();
                
            }
            else 
            {
                temp = q.front();
                while(temp != q.back())
                {
                    p.push(temp);
                    q.pop();
                    temp = q.front();   
                }
                q.pop();
            }
            return temp;
        }
        int top() 
        {
            if(!p.empty()) return p.back();
            else return q.back();
        }
        /** Returns whether the stack is empty. */
        bool empty() 
        {
            if(!p.empty()) return p.empty();
            else return q.empty();
        }
    private:
        queue<int> q,p;
};
// 只使用一个队列来实现栈
class MyStack_ {
	
	private:
		queue<int> q;
		int size;
		
	public:
		MyStack_() {
		    size = 0;
		}
		
		/** Push element x onto stack. */
		void push(int x) {
			
		    if(q.size() == 0) {
		    	q.push(x);
			}
			
			else {
				q.push(x);
				for(int i=0; i<size; i++) {
					q.push(q.front());
					q.pop();
				}
			}
			size++;
		}
		
		/** Removes the element on top of the stack and returns that element. */
		int pop() {
			int ret = q.front();
			q.pop();
		    return ret;
		}
		
		/** Get the top element. */
		int top() {
		    return q.front();
		}
		
		/** Returns whether the stack is empty. */
		bool empty() {
		    return q.size() == 0;
		}
};

class MyStack_0 {
public:
    
    queue<int> q1,q2;
    
	/** Push element x onto stack. */
    void push(int x) {
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int a = q2.front();
        q2.pop();
        return a;
    }
    
    /** Get the top element. */
    int top() {
        return q2.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q2.empty();
    }

};

int main(int argc, char const *argv[])
{

    return 0;
}


