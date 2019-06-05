/**
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
        for(int j = 0; j < s.length() ;j ++)
        {
                // 首先判断是否是[{(，入栈
                if(s[j] == '['|| s[j] == '{' || s[j] == '(')
                {
                        st.push(s[j]);
                }
                // 如果栈是空的，说明里面都是空白字符
                else if(st.empty()){
                        return false;
                }
                // 接下来判断是否能配对
                else 
                {
                        if(s[j] == ']' && st.top() != '[')
                        {
                                return false;
                        }
                        else if(s[j] == '}' && st.top() != '{')
                        {
                                return false;
                        }
                        else if(s[j] == ')' && st.top() != '(')
                        {
                                return false;
                        }
                        // 如果上面的那些情况都不成立，也就是说，配对成功，此时出栈
                        st.pop();
                }
        }
        // 最后返回这个栈是否为空，如果为空，则匹配成功，否则失败
        return st.empty();
    }
};

int main(int argc, char const *argv[])
{
        Solution s;
        bool t = s.isValid("()");
        cout << t << endl;
        return 0;
}


