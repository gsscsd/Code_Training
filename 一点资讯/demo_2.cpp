/***
 * 
 * 
 * 
 * 
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>


using namespace std;


int getfre(vector<int> num,int n)
{
        int result = 2;
        if(n < 2) return -1;
        // int i = 2;
        cout << "result " << endl;
        return result;
}

int main()
{
        int n = 0;
        cin >> n;
        vector<int> vec;
        for(int i = 0;i < n;i++)
        {
                int temp = 0;
                cin >> temp;
                vec.push_back(temp);
                cout << "====" << endl;
        }
        cout << "fre " << endl;
        int fre = getfre(vec,n);
        cout << fre << endl;
        return 0;
}

