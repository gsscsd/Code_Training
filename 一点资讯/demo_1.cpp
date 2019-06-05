/**
 * 
 * 
 * 
 * 
*/

#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main()
{
        int n = 0;
        cin >> n;
        int *vec = new int[n]();
        for(int i = 0;i < n;i++)
        {
                int temp = 0;
                cin >> temp;
                vec[temp] ++;
        }
        int result = INT32_MIN;
        int index = 0;
        for(int i = 0;i < n;i++)
        {
                if(result < vec[i])
                {
                        result = vec[i];
                        index = i;
                }
        }
        cout << index << endl;
        return 0;
}




