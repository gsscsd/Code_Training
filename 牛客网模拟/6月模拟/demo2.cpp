/**
最少回文串的个数
百分百过
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1005;

int solve(string &s)
{
    map<char,int> mp;
    for(int i = 0 ;i < s.length();i++)
    {
        mp[s[i]] += 1;
    }
    map<char,int>::iterator iter = mp.begin();
    int count = mp.size();
    for(;iter != mp.end();iter++)
    {
        if(iter -> second % 2 == 0)
            count--;
    }
    return count;
}


int main()
{
    string s;
    cin >> s;
    int len = solve(s);
    cout << len << endl;
    return 0;
}