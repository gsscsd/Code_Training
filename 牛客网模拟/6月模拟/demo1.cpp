/**
最长DNA字串
百分百过
*/

#include <bits/stdc++.h>

using namespace std;

bool isDna(char ch)
{
    if (ch == 'A' || ch == 'T' || ch == 'C' || ch == 'G')
        return true;
    return false;
}

int solve(string &s)
{
    vector<int> dp(s.length() + 1, 0);
    if (isDna(s[0]))
        dp[0] = 1;
    for (int i = 1; i < s.length(); i++)
    {
        if (isDna(s[i]) && !isDna(s[i - 1]))
            dp[i] = 1;
        else if (isDna(s[i]) && isDna(s[i - 1]))
            dp[i] = dp[i - 1] + 1;
        else
            continue;
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    string s;
    cin >> s;
    int len = solve(s);
    cout << len << endl;
    return 0;
}