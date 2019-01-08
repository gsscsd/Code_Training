/**
给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
说明：
字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。
示例 1:

输入:
s: "cbaebabacd" p: "abc"
输出:
[0, 6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
 示例 2:
输入:
s: "abab" p: "ab"
输出:
[0, 1, 2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。
*/


/**
解题思路：
滑动窗口法,：
    定义两个指针lo和hi表示窗口的左端和右端, 一个counter=p.length作为指示
    从右端开始右滑, 遇到一个p内的字符就将counter减1, 如果counter变为0判断窗口是否满足要求
    一旦窗口大小等于p的长度, 需要删去左端点字符, 删去时需要考虑是否要将counter加1
**/

#include <vector>
#include <map>
#include <set>
#include <string>


using namespace std;

class Solution 
{
    public:
        vector<int> findAnagrams(string s, string p) 
        {
            vector<int> vec;
            // 定义两个哈希表
            vector<int> vs(26,0);
            vector<int> vp(26,0);
            // 首先初始化p的哈希表
            for(auto c:p)
            {
                vp[c - 'a']++;
            }
            for(int i = 0;i < s.length();i++)
            {
                if(i >= p.size())
                {
                    // 如果超出窗口，则将对应的字符的频率减一
                    vs[s[i - p.size()] - 'a']--;
                }
                // 在窗口内的话，统计vs的字符频率
                vs[s[i] - 'a']++;
                if(vs == vp)
                {
                    vec.push_back(i - p.length() + 1);
                }
            }
            return vec;

        }
};

int main(int argc, char const *argv[])
{
    return 0;
}
