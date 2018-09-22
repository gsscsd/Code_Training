// 题目描述
// 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
// 每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。


#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
using namespace std;


class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        //方法两次的折半查找
        // int mid = int(array.size() / 2);
        // while(target )
        // {

        // }
        // 思路有两种，最简单的就是二分查找（nlogn）
        // 其次就是利用二维数组由上到下，由左到右递增的规律，
        // 那么选取右上角或者左下角的元素a[row][col]与target进行比较，
        // 当target小于元素a[row][col]时，那么target必定在元素a所在行的左边,
        // 即col--；
        // 当target大于元素a[row][col]时，那么target必定在元素a所在列的下边,
        // 即row++；
        int row = 0;
        int col = array[1].size() - 1;
        while(row <= array.size() - 1 && col >= 0)
        {
            if(target == array[row][col])
            {
                // cout << target << endl; 
                return true;
            }
            else if (target > array[row][col])
            {
                row ++;
                // cout << row << endl;
            }
            else 
            {
                col --;
                // cout << col << endl;
            }
        }
        return false;

    }
    bool find_nlogn(int target, vector<vector<int> > array)
    {
        for(int i = 0;i < array.size();i++)
        {
            int low=0;
            int high=array[i].size()-1;
            // if(target == array[i][mid]) return true;
            // else if(target < array[i][mid]) mid = (mid + 0) / 2;
            while(low <= high)
            {
                int mid = (low + high) / 2;
                if(target == array[i][mid]) return true;
                // 这里减1，是为了啥呢。。。。
                else if(target < array[i][mid]) high = mid - 1;
                else low = mid + 1;
            }
        }

        return false;
    }
};


int main()
{
    vector<vector<int> > vec;
    int aim = 0;
    string line;
    cin >> aim;
    //缓冲区里面有回车字符
    cin.get();
    // 这里while和getline的组合有些问题
    while(getline(cin,line))
    {
        if(line.compare("q") == 0)
        {
            break;
        }
        stringstream s_temp(line);
        int temp;
        vector<int> j;
        while(s_temp >> temp)
        {
            j.push_back(temp);
            
        }
        vec.push_back(j);
    }
    // for(int i = 0;i < 3; i ++)
    // {
    //     vector<int > k;
    //     for(int j = 0;j < 3;j++)
    //     {
            
    //         k.push_back(j + 1 + i * 3);
    //     }
    //     vec.push_back(k);
    // }

    // cout << vec[0].size() << endl;
    // for(auto rows:vec)
    // {
    //     cout << "hang " << endl;
    //     for(auto row:rows)
    //     {
    //         cout << row << " ";
    //     }
    //     cout << endl;
    // }
    Solution sol;
    bool temp = 1;
    // temp = sol.Find(aim,vec);
    temp = sol.find_nlogn(aim,vec);
    cout << temp << endl;

}

