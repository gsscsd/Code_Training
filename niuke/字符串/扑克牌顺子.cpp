/**
LL今天心情特别好,因为他去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张^_^)...
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子,如果抽到的话,他决定去买体育彩票,嘿嘿！！
“红心A,黑桃3,小王,大王,方片5”,“Oh My God!”不是顺子.....LL不高兴了,他想了想,决定大\小 王可以看成任何数字,
并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。
LL决定去买体育彩票啦。 现在,要求你使用这幅牌模拟上面的过程,然后告诉我们LL的运气如何， 
如果牌能组成顺子就输出true，否则就输出false。为了方便起见,你可以认为大小王是0。
*/

/**
解题思路：
第一，数组长度必须为5
第二，max-min < 5 因为存在王
第三，不存在重复的数字，除了0
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
        // 第一种做法
        bool IsContinuous( vector<int> numbers ) {

                int *temp = new int[14];
                temp[0] = -4;
                int max = -1;
                int min = 14;
                int lens = numbers.size();
                if(lens < 5) return false;
                // ps c++分配内存的时候需要赋值
                for(int j = 1; j < 14;j++)
                {
                        temp[j] = 0;
                }
                for(int i = 0;i < lens;i++)
                {
                        // cout << numbers[i] << " "<< temp[numbers[i]] << endl;
                        temp[numbers[i]]++;
                        if(numbers[i] == 0) continue;
                        if(temp[numbers[i]] > 1) return false;
                        if(max < numbers[i]) max = numbers[i];
                        if(min > numbers[i]) min = numbers[i];
                }
                delete temp;
                if(max - min <= 5)
                {
                        return true;
                }
                else 
                {
                        return false;

                }    
        }
};

int main()
{
        vector<int > vec;
        vec.push_back(0);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(6);
        vec.push_back(4);
        Solution s;
        s.IsContinuous(vec);
        return 0;
}