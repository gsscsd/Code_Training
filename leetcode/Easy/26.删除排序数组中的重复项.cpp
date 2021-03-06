/**

给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
*/


/**
解题思路：
使用vector的操作
*/


#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;



class Solution {
public:
        int removeDuplicates(vector<int>& nums) {
                int len = nums.size();
                if(len == 0) return 0;
                // 注意这里的vector删除的指针的指向
                // 这里注意删除的方式
                vector<int >::iterator low = nums.begin() + 1;
                while(low != nums.end())
                {
                        if(*low == *(low - 1))
                        {
                                // erase是删除给定的指针，并返回下一个元素的指针
                                low = nums.erase(low);
                        }
                        else
                        {
                                low ++;
                        }
                }
                return nums.size();
        }
};

// leetcode高效率答案
class  Solution_ { 
public:
// 这种方法没太懂，需要画图才能懂吧
int  removeDuplicates (vector<int>& nums) {
        int len = nums.size();
        if(len == 0)return 0;
        int end = 0;
        for(int i = 1; i < len; i++){
            if(nums[i] != nums[end]){
                end++;
                nums[end] = nums[i];
            }
        }
        return ++end;
        
    }
};


int main(int argc, char const *argv[])
{
        vector<int> vec;
        int n ;
        cin >> n;
        for(int i = 0;i < n;i++)
        {
                int temp = 0;
                cin >> temp;
                vec.push_back(temp);
        }
        Solution s;
        int t = s.removeDuplicates(vec);
        for(auto a : vec)
        {
                cout << "vec is " << a << endl;
        }
        cout << "the len is " << vec.size() << endl;
        
        return 0;
}


