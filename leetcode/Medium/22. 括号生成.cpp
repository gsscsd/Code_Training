/**
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
/**
解题思路：
深度优先搜索+回溯
以n=3为例，首先加入到list里的是“((()))”，之后完成了s为“((”时的第一个if判断，此时去下一个if判断，添加一个“）”，
继续走递归函数，之后会先判断if判断1，所以再加上以给"(",之后加入“）”，再加上“）”，
此时第二个加入list的为“(()())”。这时返回的是，当s为“(()”，这时走第二个if判断s加入“）”,
以此类推。大家完整推一次n=3就可以完全理解这个回溯算法。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string s;
        dfs(n, n, s, ans);
        return ans;
    }
  private:
    // 深度优先搜索，分别定义左边和右边的括号数目，以及当前字符串
    void dfs(int releft, int reright, string str, vector<string> &ans)
    {
        // 边界条件与递归条件
        if (releft == 0 & reright == 0)
        {
            ans.push_back(str);
            return;
        }
        if (releft <= reright)
        {
            // 递归的将将左边括号加入
            if (releft > 0)
                dfs(releft - 1, reright, str + "(", ans);
            if (reright > 0)
                dfs(releft, reright - 1, str + ")", ans);
        }
    }
};


// 另一种dfs的方法
class Solution_1 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res ;
        real("",res,n,0,0);
        return res;           
    }
    void real(string cur,vector<string>& res,int n,int left,int right)
    {
        if(right == n)
        {
            res.push_back(cur);
            return;
        }
        if(left < n)
        {
            real(cur + '(',res,n,left + 1,right);
        }
        if(right < left)
        {
            real(cur + ')',res,n,left,right + 1);
        }
        
    }
};
