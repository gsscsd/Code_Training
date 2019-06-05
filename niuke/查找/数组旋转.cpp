/*
题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 
输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 
NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;



// 解题思路
/*
1.暴力顺序遍历，时间复杂度n
2.二分查找,时间复杂度nlogn
用两个指针left,right分别指向数组的第一个元素和最后一个元素，类似于快排
3.快排，然后取第一个数，暂未实现
*/
class Solution {
public:
    // 这个考虑的更严格
    int minNumberInRotateArray(vector<int> array) {
        if(array.size() ==0)
            return 0;
        // 定义边界上参数
        int low = 0;
        int high = array.size()-1;
        int mid = low;
        // 判断边界条件，根据旋转数组可以知道
        while(array[low] >= array[high])
        {
            // 以下的代码处理非减数组
            // 考虑到非减数组，存在重复相同的数字
            if(array[low] == array[high]){
                // 遍历找到不相同的数字的下标
                for(int i=low;i<array.size();i++){
                    if(array[low]!=array[i]){
                        low = i-1;
                        break;
                    }
                }
                // 遍历找到不相同的数字的下标
                for(int i=high;i>=0;i--){
                    if(array[high]!=array[i]){
                        high = i+1;
                        break;
                    }
                }
            }
            // 以下是边界条件
            // 如果两者相邻，那么可以肯定位置
            if(high-low <= 1){
                mid = high;
                break;
            }
            // 以下是正统二分查找
            // 否则从寻找两者之间的中间值，二分查找
            mid = (low + high)/2;
            if(array[mid] >= array[low]){
                low = mid;
            }else if(array[mid] <= array[high]){
                high = mid;
            }
        }
        return array[mid];
    }
    // 顺序查找
    int seq_min(vector<int> rotateArray)
    {
        int result = rotateArray[0];
        int vec_size = rotateArray.size();
        for(int i = 1;i < vec_size;i++)
        {
            if(result > rotateArray[i])
            {
                result = rotateArray[i];
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{

    /* code */
    Solution s;
    int temp[] = {4,5,6,7,1,2,3};
    //vector<int> num = {0,1,2,3,4,5};
    vector<int> num = {4,5,6,7,1,2,3};
    // vector<int> num = {2,2,2,2,1,2};
    int result = s.minNumberInRotateArray(num);
    // 输出
    cout<<result<<endl;

    return 0;
}
