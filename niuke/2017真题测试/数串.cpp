// 题目描述
// 设有n个正整数，将他们连接成一排，组成一个最大的多位整数。
// 如:n=3时，3个整数13,312,343,连成的最大整数为34331213。
// 如:n=4时,4个整数7,13,4,246连接成的最大整数为7424613。

// 转为字符串冒泡排序，然后按序输出就好了


#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// 预定义一个函数
bool campare(string i ,string j){
    return (i+j)>(j+i);
}
int main() {
    int n;
    cin >> n;
    vector<string> sArray;
    for (int i=0;i<n;i++) {
        // 已字符串的方式读入，并加载到向量里面
        string temp;
        cin >> temp;
        sArray.push_back(temp);
    }
    // C++库里面的排序 n*log(n),三个参数，最后一个是排序方法
    // sort(sArray.begin(), sArray.end(), [](string s1, string s2){
    //     return (s1+s2) > (s2+s1);
    // });
    // 这段代码使用算法库里面的sort算法
    sort(sArray.begin(),sArray.end(),compare)
    for (auto s:sArray) {
        cout << s;
    }
    return 0;
}