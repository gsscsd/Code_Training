



/**
搜索星星的个数
*/


#include <iostream>
#include <bits/stdc++.h>

using namespace std;


#define Num 1001
#define MaxNum 100001

int m_star[Num][Num];

int getNum(int a1,int b1,int a2,int b2)
{
    int count = 0;
    for(int i = a1 ;i <= a2;i++)
    {
        for(int j = b1 ;j <= b2;j++)
        {
            count += m_star[i][j];
        }
    }
    return count;
}


int main()
{
    int n = 0;
    cin >> n;
    while(n > 0)
    {
        int x,y;
        cin >> x >> y;
        if(x > MaxNum || y > MaxNum)
        {
            cout << 0 << endl;
            return 0;
        }
        m_star[x][y] = 1;
        --n;
    }
    int m = 0;
    cin >> m;
    while(m > 0)
    {
        int a1,b1,a2,b2 ;
        cin >> a1 >> b1 >> a2 >> b2;
        if(a1 > Num || a2 > Num || b1 > Num || b2 > Num)
        {
            cout << 0 << endl;
            return 0;
        }
        int res = getNum(a1,b1,a2,b2);
        cout << res << endl;
        --m;
    }

    return 0;
}




// /**
// 搜索星星的个数
// */


// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;


// #define Num 1001
// #define MaxNum 100000

// int m_star[Num][Num] = {0};



// int main()
// {
//     int n = 0;
//     cin >> n;
//     while(n > 0)
//     {
//         int x,y;
//         cin >> x >> y;
//         if(x > MaxNum || y > MaxNum)
//         {
//             cout << 0 << endl;
//             return 0;
//         }
//         m_star[x][y] = 1;
//         --n;
//     }
//     for(int i = 1;i < Num;i++)
//     {
//         for(int j = 1;j < Num;j++)
//         {
//             m_star[i][j] += m_star[i][j - 1] + m_star[i- 1][j] + m_star[i- 1][j - 1];
//         }
//     }
//     int m = 0;
//     cin >> m;
//     while(m > 0)
//     {
//         int a1,b1,a2,b2 ;
//         cin >> a1 >> b1 >> a2 >> b2;
//         // if(a1 > Num || a2 > Num || b1 > Num || b2 > Num)
//         // {
//         //     cout << 0 << endl;
//         //     return 0;
//         // }
//         // int res = getNum(a1,b1,a2,b2);
//         res = m_star[a2][b2] - m_star[a2][b1 - 1] - m_star[a1 - 1][b2] + m_star[a1 - 1][b1 - 1];
//         cout << res << endl;
//         --m;
//     }

//     return 0;
// }

