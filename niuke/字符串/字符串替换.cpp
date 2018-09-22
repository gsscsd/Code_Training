/*
题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/ 

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// 解决方法，从前向后计算空格的个数，然后从后向前插入
class Solution {
public:
	void replaceSpace(char *str,int length) {
        
        cout << "start " << str << endl;

        if(str == nullptr || length <= 0)
        {
            return ;
        }
        int back_num = 0;
        int str_num = 0;
        for(int i = 0;str[i] != '\0';i ++)
        {
            str_num ++;
            if(str[i] == ' ')
            {
                back_num ++;
            }
        }
        // 重新定义字符串的长度，然后，从后面开始插入字符
        int new_str_length = str_num + back_num * 2;
        if(new_str_length > length) return ;
        int old_str_num = str_num;
        while(old_str_num >= 0 && new_str_length > old_str_num)
        {
            if(str[old_str_num] == ' ')
            {
                str[new_str_length --] = '0';
                str[new_str_length --] = '2';
                str[new_str_length --] = '%';
            }
            else
            {
                str[new_str_length --] = str[old_str_num];
            }
            old_str_num --;
        }

        cout << str << endl;

	}
};

int main(int argc, char const *argv[])
{
    /* code */
    char s_temp[17] = "We Are Happy";
    int len = 17;
    Solution s;
    s.replaceSpace(s_temp,17);
    return 0;
}


