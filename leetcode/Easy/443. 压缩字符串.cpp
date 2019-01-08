/**
给定一组字符，使用原地算法将其压缩。
压缩后的长度必须始终小于或等于原数组长度。
数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。
在完成原地修改输入数组后，返回数组的新长度。

进阶：
你能否仅使用O(1) 空间解决问题？

示例 1：
输入：
["a","a","b","b","c","c","c"]
输出：
返回6，输入数组的前6个字符应该是：["a","2","b","2","c","3"]
说明：
"aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。
示例 2：
输入：
["a"]
输出：
返回1，输入数组的前1个字符应该是：["a"]
说明：
没有任何字符串被替代。
示例 3：
输入：
["a","b","b","b","b","b","b","b","b","b","b","b","b"]
输出：
返回4，输入数组的前4个字符应该是：["a","b","1","2"]。
说明：
由于字符"a"不重复，所以不会被压缩。"bbbbbbbbbbbb"被“b12”替代。
注意每个数字在数组中都有它自己的位置。
注意：
    所有字符都有一个ASCII值在[35, 126]区间内。
    1 <= len(chars) <= 1000。
*/

/**
解题思路：
先排序，然后修改
时间为O(nlogn)，空间暂定
*/

#include <vector>
#include <string>

using namespace std;


// 
class Solution 
{
    public:
        int compress(vector<char>& chars) 
        {
            int csize = chars.size(),cur = 0,j = 0;
            // i 遍历所有的字符，j用来遍历重复的字符
            for(int i = 0;i < csize;i = j)
            {
                while(j < csize && chars[i] == chars[j]) ++j;
                // cur用来重新修改字符的位置
                chars[cur++] = chars[i];
                // 如果差距为1，说明没有重复的字符
                if(j - i == 1) continue;
                for(char c : to_string(j - 1))
                    chars[cur++] = c;
            }
            return cur;
        }
};


// 大神的代码
class Solution_0
{
    public:
       int compress(vector<char>& chars) 
       {
            int count = 0, prev = -1, size = chars.size();
            if (size <= 1) return 1;
            for (int i = 0; i < size; ++i)
            {
                if ((i+1 < size && chars[i] != chars[i+1]) 
                    || i+1 == size){
                    chars[count++] = chars[i];
                    string cont = to_string(i-prev);//出现次数
                    if (cont != "1")
                    {
                        // 内存的分布
                        memcpy(&chars[count], cont.c_str(), cont.size());
                        count += cont.size();
                    }
                    prev = i;
                }
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
