/**
题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/


/**
解题思路
1.根据题目可以采用迭代或者递归
2.牛客网高分答案
解释下代码，设有数组大小为5。
对于第一个for循环
第一步：b[0] = 1;
第二步：b[1] = b[0] * a[0] = a[0]
第三步：b[2] = b[1] * a[1] = a[0] * a[1];
第四步：b[3] = b[2] * a[2] = a[0] * a[1] * a[2];
第五步：b[4] = b[3] * a[3] = a[0] * a[1] * a[2] * a[3];
然后对于第二个for循环
第一步
temp *= a[4] = a[4]; 
b[3] = b[3] * temp = a[0] * a[1] * a[2] * a[4];
第二步
temp *= a[3] = a[4] * a[3];
b[2] = b[2] * temp = a[0] * a[1] * a[4] * a[3];
第三步
temp *= a[2] = a[4] * a[3] * a[2]; 
b[1] = b[1] * temp = a[0] * a[4] * a[3] * a[2];
第四步
temp *= a[1] = a[4] * a[3] * a[2] * a[1]; 
b[0] = b[0] * temp = a[4] * a[3] * a[2] * a[1];
由此可以看出从b[4]到b[0]均已经得到正确计算。
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
// 以下的代码是用暴力for循环
        int get_data(const vector<int>& A,int k)
        {
                long result = 1;
                for(int i = 0;i < A.size();++i)
                {
                        if(i != k)
                        {
                                result *= A[i];
                        }
                }
                return result;

        }
        vector<int> multiply(const vector<int>& A) {
                vector<int> B;
                int temp = 1;
                int len = A.size();
                if(len == 0) return B;
                // B.push_back(A[0]);
                for(int i = 0;i < len;i++)
                {
                        B.push_back(get_data(A,i));
                }
                return B;
        }
        vector<int> multiply_(const vector<int>& A) {
                vector<int> B;
                int len = A.size();
                if(len == 0) return B;
                // 两个for循环
                B.push_back(1);
                // 注意边界
                for(int i = 1;i < len ;i++)
                {
                        B.push_back(B[i - 1] * A[i - 1]);
                }
                int temp = 1;
                // 注意边界
                for(int j = len - 2;j >= 0 ; j --)
                {
                        temp *= A[j + 1];
                        B[j] *= temp;
                }
                return B;
        }

};

int main(int argc, char const *argv[])
{
        return 0;
}








