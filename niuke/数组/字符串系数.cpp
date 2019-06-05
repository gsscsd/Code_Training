#include <iostream>
#include <vector>
#include <string>
#include <map>


using namespace std;


int main()
{
    int k;
    cin >> k;
    k = 2;
    string s0,s1;
    cin >> s0;
    cin >> s1;

    map<string,int> dict;
    int s0_len = s0.size();
    int s1_len = s1.size();
    if(k > s0_len) return 0;
    cout << "s0 len is " << s0_len << " s1 len is " << s1_len << endl;
    for (int i = 0;i < s0_len - k + 1;i++)
    {
        string key = s0.substr(i,k);
        // cout << " key " << key << " i " << i << endl;
        if(!dict.count(key))
        {
            dict[key] = 0;
        }
    }
    for (int j = 0;j < s1_len - k + 1;j++)
    {
        string temp = s1.substr(j,k);
        // cout << " temp " << temp << " j " << j << endl;
        if(!dict.count(temp)) continue;
        else
        {
            dict[temp] += 1;
        }
    }
    int count = 0;
    map<string,int>::iterator itor = dict.begin();
    for(;itor != dict.end();itor++)
    {
        // cout << "first is " << itor -> first << " second is " << itor -> second << endl;
        count += itor -> second;
    }
    cout << "the last result is " << count << endl;
}