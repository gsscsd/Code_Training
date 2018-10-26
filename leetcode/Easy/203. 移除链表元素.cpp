/**
删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5
*/

/**
解题思路：

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode 
{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(NULL){};
};

class Solution 
{
    public:
        ListNode* removeElements(ListNode* head, int val) 
        {
            if(!head) return NULL;
            // 为了方便可以在头节点添加一个头指针
            ListNode *pHead = new ListNode(INT32_MIN);
            pHead -> next = head;
            ListNode *pre = pHead;
            while(head != NULL)
            {
                if(val == head -> val)
                {
                    ListNode *ln = head;
                    pre -> next = head -> next;
                    head = pre -> next;
                    delete ln;
                }
                else
                {
                    pre = head;
                    head = head -> next;
                }
            }
            return pHead -> next;
        }
};

int main(int argc, char const *argv[])
{
    return 0;
}

