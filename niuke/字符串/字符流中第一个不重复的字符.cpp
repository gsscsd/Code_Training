/**
题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，
当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
*/

/**
解题思路：
1.map映射
2.数组下标对应
3.队列实现

思路：时间复杂度O（1），空间复杂度O（n）
        1、用一个128大小的数组统计每个字符出现的次数
        2、用一个队列，如果第一次遇到ch字符，则插入队列；其他情况不在插入
        3、求解第一个出现的字符，判断队首元素是否只出现一次，如果是直接返回，否则删除继续第3步骤 
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
  public:
    //Insert one char from stringstream
    void Insert(char ch)
    {
        // 以下是map
        // vec.push_back(ch);
        // mp[char] ++;
        // 以下是char数组
        // s += ch;
        // hash[ch] += 1;
        // 队列的方式
        ++cnt[ch - '\0'];
        data.push(ch);
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        // 以下是map
        // for(int i = 0 ;i < vec.size();++i)
        // {
        //         if(mp[vec[i]] == 1)
        //         {
        //                 return vec[i];
        //         }
        // }
        // return '#';
        // 以下是数组
        // for(int i = 0; i < s.length();i++)
        // {
        //         if(hash[s[i]] == 1)
        //         {
        //                 return s[i];
        //         }
        // }
        // return '#';
        // 队列的方式，严格意义上时间复杂度倒也不算是O(1)
        while (!data.empty() && cnt[data.front()] >= 2)
            data.pop();
        if (data.empty())
            return '#';
        return data.front();
    }

  private:
    // mapde 方式
    // unordered_map<char ,int >  mp;
    // vector<char> vec;
    // 根据char类型可以推断 字符8位字节的类型，最大值为2^8-1；
    // char hash[256] = {0};
    // string s="";
    queue<char> data;
    unsigned cnt[128] = {0};
};

int main()
{
    return 0;
}