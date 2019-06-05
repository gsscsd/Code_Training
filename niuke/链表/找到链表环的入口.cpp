/**
题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
*/

/**
解题思路：
1.双指针，一个走一步，一个走两步，当两者都相等的时候，就找到了环内的某一个点
//此时只需要把其中的一个指针重新指向链表头部，另一个不变（还在环内），
//这次两个指针一次走一步，相遇的地方就是入口节点。
//左神讲的
//先说个定理：两个指针一个fast、一个slow同时从一个链表的头部出发
//fast一次走2步，slow一次走一步，如果该链表有环，两个指针必然在环内相遇
//此时只需要把其中的一个指针重新指向链表头部，另一个不变（还在环内），
//这次两个指针一次走一步，相遇的地方就是入口节点。
//这个定理可以自己去网上看看证明。
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};


class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode *p0 = pHead;
        ListNode *p1 = pHead;
        if(!pHead) return NULL;
        while(p0 != NULL && p1->next != NULL)
        {
                p0 = p0->next;
                p1 = p1->next->next;
                if(p1 == p0)
                {
                        ListNode *pNew = pHead;
                        while(pNew != p0)
                        {
                                pNew = pNew -> next;
                                p0 = p0 -> next;
                        }
                        return pNew;
                }

        }
        return NULL;
    }
};



int main(int argc, char const *argv[])
{
        
        return 0;
}


