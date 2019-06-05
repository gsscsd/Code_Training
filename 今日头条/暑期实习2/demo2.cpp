/**
字符串查找匹配 
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string& s, char delimiter)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

bool isfind(const string &str1,vector<string> &strs)
{
    for(int i = 0;i < strs.size();i++)
    {
        string::size_type position;
        position = str1.find(strs[i]);
        if (position == str1.npos)  //如果没找到，返回一个特别的标志c++中用npos表示，我这里npos取值是4294967295，
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str1,str2;
    cin >> str1 >> str2;
    vector<string> strs = split(str2," ");

    bool isOk = isfind(str1,strs);
    if(isOk) cout << "True" << endl;
    else cout << "False" << endl;

    return 0;
}