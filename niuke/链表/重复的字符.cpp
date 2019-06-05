#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// 判断是否存在连续重复的字符

class Solution{
    public:
    bool isRepeat(vector<char> &vec)
    {
        
        bool flag = false;
        char pre = vec[0];
        for(int i = 1;i < vec.size();i++)
        {
            if(pre == vec[i])
            {
                flag = !flag;
                break;
            }
            else
            {
                pre = vec[i];
            }
        }
        return flag;

    }

};

int main()
{
    vector<char> s_temp;
    Solution s;
    string lines;
    getline(cin,lines);
    char ch;
    stringstream ss(lines);
    while(ss >> ch)
    {
        s_temp.push_back(ch);
    }
    bool t = s.isRepeat(s_temp);
    cout << t << endl;
}