/**
bitmap算法
*/

#include <iostream>
#include <bitset>
#define N 100
using namespace std;
 
 
int main() {
       int a[] = {12, 5, 1, 89, 64, 49, 77, 91, 3, 0, 32, 50, 99};
       int length = sizeof(a) / sizeof(int);
 
 
       //直接使用C++bitset，申请Nbit的空间，每一位均设置为0
       bitset<N> bitmap; 
 
 
       //遍历待排序数组，将bitmap中对应位设置为1
       for (int i = 0; i < length; i++)
            bitmap.set(a[i], 1);
 
 
       //输入排序结果
       for (int i = 0; i < N; ++i) {
            if (bitmap[i])
               cout << i << " ";
       }
       cout << endl;
}