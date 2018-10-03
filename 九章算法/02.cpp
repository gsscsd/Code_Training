/**
 * 
 * 
 * 
*/

#include <cstring>
#include <string>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <climits>
#include <bitset>
#include <set>
using namespace std;
#define mod 1000000007
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
typedef long long LL;

struct node
{
        int L, R;
} E[10005];
bool cmp(node a, node b)
{
        if (a.L == b.L)
                return a.R < b.R;
        return a.L < b.L;
}
int n;
int main()
{
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
                scanf("%d%d", &E[i].L, &E[i].R);
        }
        sort(E, E + n, cmp);
        priority_queue<int, vector<int>, greater<int>> p;
        p.push(E[0].R);
        for (int i = 1; i < n; i++)
        {
                if (E[i].L >= p.top())
                {
                        p.pop();
                        p.push(E[i].R);
                }
                else
                        p.push(E[i].R);
        }
        cout << p.size() << endl;
        return 0;
}
