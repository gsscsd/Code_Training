/**
给定一个单词，你需要判断单词的大写使用是否正确。
我们定义，在以下情况时，单词的大写用法是正确的：
全部字母都是大写，比如"USA"。
单词中所有字母都不是大写，比如"leetcode"。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
否则，我们定义这个单词没有正确使用大写字母。
示例 1:
输入: "USA"
输出: True
示例 2:
输入: "FlaG"
输出: False
注意: 输入是由大写和小写拉丁字母组成的非空单词。
*/

#include <string>


using namespace std;


class Solution 
{
    public:
        bool detectCapitalUse(string word) 
        {
            // 使用系统函数判断小写写
            if(islower(word[0]))
            {
                for(int i = 1; i < word.size();i++)
                    if(isupper(word[i])) return false;
            }
            // 使用自定义函数判断大写
            else  
            {
                // 如果第二个字符是大写的字符
                if(isupper(word[1]))
                {
                    for(int i = 2; i < word.size();i++)
                        if(islower(word[i])) return false;
                }
                else  
                {
                    for(int i = 2 ; i < word.size();i++)
                        if(isupper(word[i])) return false;
                }

            }
            return true;
        }
};


// 大神的解法，判断第2个字符及其前后的字符即可
class Solution_ {
public:
	bool detectCapitalUse(string word) {
		for (int i = 1; i < word.size(); ++i)
		{
			if (word[i - 1] >= 'a' && word[i - 1] <= 'z' && word[i] >= 'A' && word[i] <= 'Z' || i != 1 && word[i - 1] >= 'A' && word[i - 1] <= 'Z' && word[i] >= 'a' && word[i] <= 'z') return false;
		}
		return true;
	}
};

// 涉及使用api来做
class Solution_1 {
public:
    bool detectCapitalUse(string word) {
        static string upp = "QWERTYUIOPASDFGHJKLZXCVBNM";
        static string low = "qwertyuiopasdfghjklzxcvbnm";
        
        auto pos1 = word.find_first_of(upp);
        if(pos1 == string::npos)
        {
            return true;
        }
        
        auto pos2 = word.find_first_of(low);
        if(pos2 == string::npos)
        {
            return true;
        }
        
        auto pos3 = word.find_last_of(upp);
        if(pos3 == 0)
        {
            return true;
        }
        
        return false;
    }
};