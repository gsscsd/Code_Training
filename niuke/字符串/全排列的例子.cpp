// 这个是一个测试的例子
// 全排列的例子
// 直接抄的博客，反正看不懂

#include<iostream>
#include<algorithm>
 
using namespace std;
 
int arry[3] = { 1,2,3 };
 
void Recursion(int s, int t)
{
	if (s == t)
        // for_each函数+lambda
        // 递归边界条件
		for_each(arry, arry + 3, [](int i) {printf("%d", i); }), printf("\n");
	else
	{
		for (int i = s; i <= t; i++)
		{
			swap(arry[i], arry[s]);
            // 接下来处理后面的字符
			Recursion(s + 1, t);
			swap(arry[i], arry[s]);
		}
	}
}

//字典序
void Permutation()
{
	int len = 3;
	int j, k;
 
	while (true)
	{
		printf("%d%d%d\n", arry[0], arry[1], arry[2]);
 
		for (j = len - 2; j >= 0 && arry[j] > arry[j + 1]; j--);//注意此处 j >= 0 判断条件在前
 
		if (j < 0) return;//结束
		
		for (k = len - 1; k > j&&arry[k] < arry[j]; k--);
 
		swap(arry[k], arry[j]);
 
		for (int l = j + 1, r = len - 1; l < r; l++, r--)
			swap(arry[l], arry[r]);
	}
}


// 直接利用算法库
void Permutation()
{
	do
		printf("%d%d%d\n", arry[0], arry[1], arry[2]);
	while (next_permutation(arry, arry + 3));
	
}
 
int main()
{
 
	// Recursion(0, 2);
    Permutation();
	return 0;
}
