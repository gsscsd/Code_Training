/**
给出3个正整数A B C，求A^B Mod C。
例如，3 5 8，3^5 Mod 8 = 3。 
*/

// #include <iostream>
// #include <cmath>
// #include <algorithm>

// #define max_data 1000000000

// using namespace std;

// int getmod(int a,int b,int c)
// {
//         if(a <= max_data && a >= 1&&b <= max_data && b >= 1&&c <= max_data && c >= 1)
//         {
//                 long temp = pow(a,b);
//                 return temp % c;
//         }
//         else
//         {


//         }
// }

// int main()
// {
//         int a,b,c;
//         cin >> a >> b >> c;
//         int mod = getmod(a,b,c);
//         cout << mod << endl;
//         return 0;
// }

// 快速幂算法

#include <iostream>

using namespace std;

int PowerMod(long long a,long long b,long long c)
{
    int ans = 1;
    a = a % c;
    while(b > 0)
    {
        if(b & 1 != 0)
            ans = ans * a % c;
        a = (a * a) % c;
        b >>= 1;
    }
    return ans; 
}
int main()
{
    long long a,b,c;
    cin >> a >> b >> c;
    a = PowerMod(a,b,c);
    cout << a;
    return 0;
}


