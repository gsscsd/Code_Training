

/**
IO
read(num);    //读入一个数num（任意整数类型，下同）
read(num1,num2,num3,num4); //读入任意多个数
read(arr,n); //对一个整数数组arr读入n个值，[0,n-1]
read(arr,first,last); //对一个整数数组arr读入区间last-first+1个值，[first,last]
read(s); //读入一个字符串数组（string和char数组都支持）
print(num); //输出一个数num
print(num1,num2,num3,num4); //输出任意多个数，中间用空格隔开
print(arr,n); //对一个整数数组arr输出n个值，[0,n-1]，中间用空格隔开
print(arr,first,last); //对一个整数数组arr输出last-first+1个值，[first,last]，中间用空格隔开
//read()有返回值，遇到EOF返回0。多组数据时可以放心使用while(read(n)){}
//至于字符串的输出没有进行优化，测试显示直接cout或者printf比较快

Function
gcd(a,b); //求两数gcd（任意整数类型，下同）
lowbit(x); //求一个整数的lowbit
mishu(x); //判断一个数是不是2的幂
q_mul(a,b,p); //求(a*b)%p的值，防止溢出,O(logN)
f_mul(a,b,p); //求(a*b)%p的值，防止溢出,O(1),可能丢失精度
q_pow(a,b,p); //求(a^b)%p的值，不防溢出，O(logN)
s_pow(a,b,p); //求(a^b)%p的值，防溢出，O(logN*logN)
ex_gcd(a,b,x,y); //扩展GCD
com(m,n); //求C(m,n)
isprime(num); //判断一个数是否质数 
*/

//XDDDDDDi
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MT make_tuple
#define MP make_pair
#define pii pair<int, int>
#define pdd pair<double, double>
#define F first
#define S second

#define MOD 1000000007
#define PI (acos(-1.0))
#define EPS 1e-6
#define MMT(s, a) memset(s, a, sizeof s)
#define GO(i, a, b) for (int i = (a); i < (b); ++i)
#define GOE(i, a, b) for (int i = (a); i <= (b); ++i)
#define OG(i, a, b) for (int i = (a); i > (b); --i)
#define OGE(i, a, b) for (int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef stringstream sstm;
int fx[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

template <typename T>
using maxHeap = priority_queue<T, vector<T>, less<T>>;
template <typename T>
using minHeap = priority_queue<T, vector<T>, greater<T>>;

inline char nc()
{
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}
#define nc getchar
template <typename T>
inline int read(T &sum)
{
    char ch = nc();
    if (ch == EOF || ch == -1)
        return 0;
    int tf = 0;
    sum = 0;
    while ((ch < '0' || ch > '9') && (ch != '-'))
        ch = nc();
    tf = ((ch == '-') && (ch = nc()));
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + (ch - 48), ch = nc();
    (tf) && (sum = -sum);
    return 1;
}
template <typename T, typename... Arg>
inline int read(T &sum, Arg &... args)
{
    int ret = read(sum);
    if (!ret)
        return 0;
    return read(args...);
}
template <typename T1, typename T2>
inline void read(T1 *a, T2 num)
{
    for (int i = 0; i < num; i++)
    {
        read(a[i]);
    }
}
template <typename T1, typename T2>
inline void read(T1 *a, T2 bn, T2 ed)
{
    for (; bn <= ed; bn++)
    {
        read(a[bn]);
    }
}
inline void read(char *s)
{
    char ch = nc();
    int num = 0;
    while (ch != ' ' && ch != '\n' && ch != '\r' && ch != EOF)
    {
        s[num++] = ch;
        ch = nc();
    }
    s[num] = '\0';
}
inline void read(string &s)
{
    static char tp[1000005];
    char ch = nc();
    int num = 0;
    while (ch != ' ' && ch != '\n' && ch != '\r' && ch != EOF)
    {
        tp[num++] = ch;
        ch = nc();
    }
    tp[num] = '\0';
    s = (string)tp;
}
template <typename T>
inline void print(T k)
{
    int num = 0, ch[20];
    if (k == 0)
    {
        putchar('0');
        return;
    }
    (k < 0) && (putchar('-'), k = -k);
    while (k > 0)
        ch[++num] = k % 10, k /= 10;
    while (num)
        putchar(ch[num--] + 48);
}
template <typename T, typename... Arg>
inline void print(T k, Arg... args)
{
    print(k), putchar(' ');
    print(args...);
}
template <typename T1, typename T2>
inline void print(T1 *a, T2 num)
{
    print(a[0]);
    for (int i = 1; i < num; i++)
    {
        putchar(' '), print(a[i]);
    }
}
template <typename T1, typename T2>
inline void print(T1 *a, T2 bn, T2 ed)
{
    print(a[bn++]);
    for (; bn <= ed; bn++)
    {
        putchar(' '), print(a[bn]);
    }
}
/*math*/
template <typename T>
inline T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }
template <typename T>
inline T lowbit(T x) { return x & (-x); }
template <typename T>
inline bool mishu(T x) { return x > 0 ? (x & (x - 1)) == 0 : false; }
template <typename T1, typename T2, typename T3>
inline ll q_mul(T1 a, T2 b, T3 p)
{
    ll w = 0;
    while (b)
    {
        if (b & 1)
            w = (w + a) % p;
        b >>= 1;
        a = (a + a) % p;
    }
    return w;
}
template <typename T, typename T2>
inline ll f_mul(T a, T b, T2 p) { return (a * b - (ll)((long double)a / p * b) * p + p) % p; }
template <typename T1, typename T2, typename T3>
inline ll q_pow(T1 a, T2 b, T3 p)
{
    ll w = 1;
    while (b)
    {
        if (b & 1)
            w = (w * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return w;
}
template <typename T1, typename T2, typename T3>
inline ll s_pow(T1 a, T2 b, T3 p)
{
    ll w = 1;
    while (b)
    {
        if (b & 1)
            w = q_mul(w, a, p);
        b >>= 1;
        a = q_mul(a, a, p);
    }
    return w;
}
template <typename T>
inline ll ex_gcd(T a, T b, T &x, T &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return (ll)a;
    }
    ll r = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return r; /*gcd*/
}
template <typename T1, typename T2>
inline ll com(T1 m, T2 n)
{
    int k = 1;
    ll ans = 1;
    while (k <= n)
    {
        ans = ((m - k + 1) * ans) / k;
        k++;
    }
    return ans;
}
template <typename T>
inline bool isprime(T n)
{
    if (n <= 3)
        return n > 1;
    if (n % 6 != 1 && n % 6 != 5)
        return 0;
    T n_s = floor(sqrt((db)(n)));
    for (int i = 5; i <= n_s; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}
/* ----------------------------------------------------------------------------------------------------------------------------------------------------------------- */

int main()
{

    return 0;
}