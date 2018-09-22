//
// Created by apple on 18/1/13.
//

#include <iostream>
#include "../include/HashWordCut.h"

using namespace std;

void prints(string str);

int main()
{
    // cout << "Hello World"<<endl;
    string text = "中国人民共和国首都是北京，中关村在海淀区。";

   cout << "row string is " << text << endl;
   WordCut wordcut;
    // cout << "print all" << endl;
    wordcut.printAll();
    cout << "cut words" << endl;
   wordcut.word_cut(text);
    cout<<"***************************************"<<endl;
    return 0;
}

// 测试中英文在C++的编码的字节数目
void test()
{
    string a = "0a,\n你好，a";

    string  ascii_str = a.substr(0,4);
    //截取包含英文，换行，英文符号","
    //都是ascii编码里面的

    string gbk_str = a.substr(4,10);
    //截取汉字“好，”，因为“你”占用的是3B，所以下标要注意
    //又因为“好”和汉字符号“，”，所以也要注意截取3B+3B

    string both_str = a.substr(4,9);
    //包含汉字和英文，只要计算好所占的字节就行

    cout<<ascii_str<<endl;
    cout<<gbk_str<<endl;
    cout<<both_str<<endl;
}
void prints(string str)
{
    int length = str.length();
    for (int i = 0 ; i < length ; i += 3)
    {
        cout << str.substr(i,6) << endl;
    }
}

