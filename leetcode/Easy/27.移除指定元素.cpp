/**

给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
*/

/**

*/


#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
        int removeElement(vector<int>& nums, int val) {

                int len = nums.size();
                if(len == 0) return 0;
                vector<int >::iterator low = nums.begin();
                while(low != nums.end())
                {
                        if(*low == val)
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

int main(int argc, char const *argv[])
{
        
        return 0;
}



