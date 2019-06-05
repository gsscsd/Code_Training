/**
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:

输入: [0,1,0,3,12]
输出: [1,3,12,0,0]

说明:
必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
*/

/**
解题思路：
这是一个排序相关的算法
采用双指针来操作
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
    public:
        void moveZeroes(vector<int>& nums) 
        {
            // i指向0，j指向非0
            int i  = 0,j = 1;
            while(j < nums.size() && i < nums.size())
            {
                if(nums[i] != 0)
                {
                    i ++;
                }
                else
                {
                    // swap(nums[i],nums[j]);
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
                //j永远在i的后面
                if(j < i) j = i ;
                if(nums[j] == 0)
                {
                    j++;
                }
            }
            
        }
};

// 应用vector的特性，直接删除，然后在最后面添加0
class Solution_0 {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(auto it=nums.end()-1;it>=nums.begin();it--)
        {
            if(*it==0)
            {
                nums.erase(it);
                nums.push_back(0);
            }
        }
       
    }
};

// 另一种，先将0覆盖，然对后面的数据重新赋值为0
class Solution_ {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[j]=nums[i];
                j++;
            }
        }
        for(int i=j;i<nums.size();i++){
            nums[i]=0;
        }
        return;
    }
};

int main(int argc, char const *argv[])
{
    
    return 0;
}
