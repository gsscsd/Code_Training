/**
你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。
由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。

假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。

你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。
实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。

示例:

给定 n = 5，并且 version = 4 是第一个错误的版本。

调用 isBadVersion(3) -> false
调用 isBadVersion(5) -> true
调用 isBadVersion(4) -> true

所以，4 是第一个错误的版本。 
*/

/**
解题思路：
有序的数组查找问题
是否采用二分查找呢？
时间复杂度初步分析O(n)或者O(logn),上限是O(n)
除此之外是否考虑没有错误版本的问题，以及其他特殊情况呢？
*/

#include <iostream>
#include <vector>

using namespace std;

bool isBadVersion(int version);

class Solution 
{
    public:
        int firstBadVersion(int n) 
        {
            int i = 1,j = n;
            int mid = 0;
            // 此题遇见的问题就是加法溢出
            // 解决加法的溢出，参加下面
            while(i <= j)
            {
                // 中间值
                // 解决加法溢出的一种方法
                // mid = i / 2 + j / 2;
                // 第二种解决溢出的方法
                mid = i + (j - i) / 2;
                if(isBadVersion(mid)) j = mid - 1;
                else i = mid + 1;
            }
            return i;
        }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
