/**
题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？ 
*/

/**
解题思路：
1.切分string，然后，在反转vector,本地通过，但是线上没有通过
2.大神的代码，每个字符去依次处理
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


class Solution {
public:

    string ReverseSentence(string str) {

        // 注意这里的数据操作，模拟了split函数
        vector<string> vec;
        string t;
        // 把string传给stringstream
        stringstream ss(str);
        // 然后用getline和while来切分
        while(getline(ss,t,' '))
        {
            vec.push_back(t);
        }
        // for(auto v:vec)
        // {
        //     cout << v << endl;
        // }
        t = "";
        for(int i = vec.size()  -  1;i >= 0 ;--i)
        {
            cout << vec[i] << endl;
            t += vec[i];
            t += " ";
        }   
        // cout << t << endl;
        // cout << t.substr(1) << endl;
        int len = t.length();
        return t.substr(0,len - 1);     
    }

    // 大神的代码一个一个字符的处理
    string ReverseSentence_(string str)
    {
        string res = "", tmp = "";
        // 对所有的字符去遍历
        for(unsigned int i = 0; i < str.size(); ++i){
            // 寻找到空格就将之前的单词头插入
            if(str[i] == ' ') res = " " + tmp + res, tmp = "";
            // 如果不是空格，就将字符累加形成单词
            else tmp += str[i];
        }
        // 如果，字符的长度不为空
        cout << "before temp " << res << endl;
        if(tmp.size()) res = tmp + res;
        cout << "after temp " << res << endl;
        return res;
    }
};

int main()
{
    string str = "I am a student.";
    Solution s;
    string st = s.ReverseSentence_(str);
    // cout << st << endl;

}