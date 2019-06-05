/***
背包问题
*/

#include <bits/stdc++.h>

using namespace std;

const int maxm = 1001;
const int maxn = 101;

// int price[maxn] = {0};
// int hot[maxn] = {0};

int sovle(vector<int> &price, vector<int> &hot, int money)
{
    // int res = 0;
    int n = price.size();
    vector<vector<int> > dp(n + 1, vector<int>(money + 1, 0));

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < money + 1; j++)
        {
            if (j < price[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j - price[i - 1]] + hot[i - 1], dp[i - 1][j]);
        }
    }
    cout << "-----------> matrix" << endl;
    for(auto rows:dp)
    {
        for(auto col:rows)
        {
            cout << col << " ";
        }
        cout << endl;
    }

    return dp[n][money];
}

int main()
{
    int money = 0;
    cin >> money;
    getchar();
    string input;
    getline(cin, input);
    stringstream strprice(input);
    int num;
    vector<int> price;
    while (strprice >> num)
    {
        price.push_back(num);
    }
    // getchar();
    vector<int> hot;
    getline(cin, input);
    stringstream strhot(input);
    while (strhot >> num)
    {
        hot.push_back(num);
    }
    for_each(price.begin(),price.end(),[](int i){cout << i << " ";});
    cout << endl;
    for_each(hot.begin(),hot.end(),[](int i){cout << i << " ";});
    cout << endl;

    int res = sovle(price, hot, money);
    cout << res << endl;

    return 0;
}