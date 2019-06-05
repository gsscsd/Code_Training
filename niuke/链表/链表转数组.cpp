/*
题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
// 解决方法，每次都在头部插入，也就是头插法。
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vec;
        if(head != NULL)
        {
            vec.insert(vec.begin(),head->val);
            while(head->next!= NULL)
            {
                vec.insert(vec.begin(),head ->next -> val);
                head = head -> next;
            }      
        }
        return vec;
    }
};


int main()
{
    

}