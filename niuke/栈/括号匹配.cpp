/**
括号匹配
*/

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
    stack<char> a;
    int flag = 1, i;
    char ch[100];
    cin >> ch;
    for (i = 0; i < strlen(ch); i++)
    {
        if (ch[i] == '{' || ch[i] == '(' || ch[i] == '[')
            a.push(ch[i]);
        else
        {
            if (a.empty() == true)
            {
                flag = 0;
                break;
            }
            else if ((ch[i] == '}' && a.top() == '{') || (ch[i] == ')' && a.top() == '(') || (ch[i] == ']' && a.top() == '['))
                a.pop();
            else
            {
                flag = 0;
                break;
            }
        }
    }
    if (flag == 0)
        cout << 0;
    else
        cout << 1;
}