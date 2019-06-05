/**
题目描述
统计一个数字在排序数组中出现的次数。
*/

/**
解题思路：
1.直接for循环遍历
2.二分查找
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    // 1.用map数组
    int GetNumberOfK(vector<int> data ,int k) {
        map<int,int> temp;
        for(int i = 0;i < data.size();++i)
        {
            if(!temp.count(data[i])) temp[data[i]] = 1;
            else temp[data[i]] += 1;
        }
        map<int,int>::iterator it;
        if(!temp.count(k)) return 0;
        return temp[k];
    }
    // 2.有序的情况下，调用系统的二分查找的api
    int GetNumberOfK_(vector<int> data ,int k) {
        auto resultPair = equal_range(data.begin(), data.end(),k);
        return resultPair.second - resultPair.first;
    }
    
    // 3.写法在下面，前面两个是辅助函数
    // 手动写二分查找，存在两中方式，递归和迭代
    // 递归的写法
    int getFirstK(vector<int> array,int k,int start ,int end)
    {
        if(start > end) return -1;
        // int mid = (start + end) / 2;
        // 移位速度更快一些
        int mid = (start + end) >> 1;
        if(array[mid] > k)
        {
            // 递归计算前半部分数组
            return getFirstK(array,k,start,mid - 1);
        }
        else if(array[mid] < k)
        {
            // 递归计算后半部分数组
            return getFirstK(array,k,mid + 1,end);
        }
        // 注意，这里的代码
        else if(mid - 1 >= 0 && array[mid - 1] == k)
        {
            return getFirstK(array,k,start,end - 1);
        }
        else return mid;
    }
    // 递推的写法
    int getLastK(vector<int> array,int k,int start,int end)
    {
        int len = array.size();
        int mid = (start + end) >> 1;
        while(start <= end)
        {
            if(array[mid] > k) 
            {
                end = mid - 1;
            }
            else if(array[mid] < k)
            {
                start = mid + 1;
            }
            // 如果没有到达尾部
            else if(mid + 1 < len && array[mid + 1] == k){
                start = mid + 1;
            }
            else
            {
                return mid;
            }
            mid = (start + end) >> 1;
        }
    }
    // 3.手动实现二分

    int GetNumberOfK_1(vector<int> data ,int k) {
        int len = data.size();
        if(len <= 0) return 0;
        else
        {
            int firstk = getFirstK(data,k,0,len - 1);
            int lastk = getLastK(data,k,0,len - 1);
            if(firstk != -1 && lastk != -1)
            {
            return lastk - firstk + 1;
            }
        }
    }

};


int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(3);
    vec.push_back(3);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    int k = 4;
    Solution s;
    s.GetNumberOfK(vec,k);
    return 0;

}
