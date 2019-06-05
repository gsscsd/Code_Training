/**
题目描述：
到了开学季，新生又要开始军训了。

现在有N个学生，需要站成一排，并且为了队伍的美观，要求任意相邻两个人的身高差的绝对值<=K.

现在已知这N名学生的身高分别是a[0],a[1],,,a[N-1]，请问有多少种满足要求的排列方式？

输入
第一行输入两个整数N和K。(1<=N<=10, 0<=K<=10^5)

第二行输入N个整数a[0],a[1],,,a[N-1]。(0<=a[i]<=10^5)

输出
输出1个数，表示满足要求的排列数目。

样例输入
4 1
1 2 1 3
样例输出
4

*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>


using namespace std;


int jiecheng(int m)
{
        int result = 1;
        for(int i = 0;i < m ;i++)
        {
                result *= i;
        }
        return result;

}


int main()
{
        int n = 0,k = 0;
        cin >> n;
        cin >> k;
        if(n == 1) return 1;
        vector<int> vec;
        for(int i = 0 ; i < n ; i++)
        {
                int temp = 0;
                cin >> temp;
                vec.push_back(temp);
        }

        map<int ,int > mp_fre;
        map<int ,int > mp_count;

        // 遍历找到重复的数字
        for(int i = 0;i < n ;i++)
        {
                if(!mp_fre.count(vec[i])) mp_fre[vec[i]] = 0;
                else mp_fre[vec[i]] ++;
        }
        // 统计重复数字的频率
        for(int i = 0; i < mp_fre.size();i++)
        {
                if(!mp_fre.count(mp_fre[i])) mp_fre[mp_fre[i]] = 0;
                else mp_fre[mp_fre[i]] ++;
        }
        // 
        int count = 0;
        // map<int ,int >::iterator it = mp_count.begin();
        // if(;it != mp_count.end();it++)
        // {
        //         count += (jiecheng(mp_count -> second))
        // }
        for(int i = 0;i < mp_count.size();i++)
        {
                count += (jiecheng(mp_count[i] / jiecheng(2))) / jiecheng(mp_count[i] - 2);
        }
        int index = 0;
        // 寻找到分界点
        for(int i = 1;i < n;i++)
        {
                if(abs(vec[i - 1] - vec[i]) > k)
                {
                        index = i;
                        break;
                }
        }
        // 


        return 0;
}