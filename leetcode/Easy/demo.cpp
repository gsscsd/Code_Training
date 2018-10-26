/**

反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
进阶:
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
*/

/**
解题思路：
递归或者迭代
方法上都是头插法
时间复杂度为O(n)，空间复杂度为O(1)
*/


#include <iostream>
#include <vector>

using namespace std;

struct ListNode 
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x),next(NULL){};
};

class Solution 
{
    public:
        // 第一种方法迭代的方法,通过没有问题
        ListNode* reverseList(ListNode* head) 
        {
            if(!head) return NULL;
            ListNode *pHead = new ListNode(INT32_MIN);
            ListNode *ptemp = NULL;
            while(head)
            {
                ptemp = head -> next;
                head -> next = pHead -> next;
                pHead -> next = head;  
                head = ptemp;
            }
            return pHead -> next;
        }
        // 第二种方法用递归的方法
        // 递归的方法比较难想，应该如何进入递归，又应该何时出来
        ListNode* reverseList_(ListNode *head)
        {
            
        }
        // 递归计算的函数
        // 考虑一下，是否还需要单独的去开一个函数呢？
        ListNode* help(ListNode *head)
        {
            if(!head) return NULL;
            
        }
        

};



int main(int argc, char const *argv[])
{
    
    
    return 0;
}
