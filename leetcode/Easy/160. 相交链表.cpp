/**
编写一个程序，找到两个单链表相交的起始节点。

例如，下面的两个链表：

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
在节点 c1 开始相交。


注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
*/

/**
剑指offer的题目
多种高效的算法
1.大神的代码，还是不太理解
2.最简单的思路
计算出两个的长度，然后，长度差就是交点
*/

#include <iostream>
#include <stack>
#include <vector>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};


class Solution{
    public:
        // 最简单的，最朴素的想法
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
        {
            if(!headA || !headB) return NULL;
            int a_len = 0,b_len = 0;
            ListNode *pa = headA;
            ListNode *pb = headB;

            while(pa != NULL)
            {
                a_len ++;
                pa = pa -> next;
            }
            while(pb != NULL)
            {
                b_len ++;
                pb = pb -> next;
            }

            // 计算a,b的长度
            int c = a_len > b_len ? a_len - b_len : b_len - a_len;

            // 定义两个长短的链表，让长的先走
            ListNode *pc,*pd;
            if(a_len > b_len)
            {
                pc = headA;
                pd = headB;
            }
            else 
            {
                pc = headB;
                pd = headA;
            }
            while(c > 0)
            {
                pc = pc -> next;
                c--;
            }
            while(pd != pc)
            {
                pd = pd -> next;
                pc = pc -> next;
            } 
            return pd;
        }
        // 大神的代码
        ListNode *getIntersectionNode_(ListNode *headA,ListNode *headB)
        {
            ListNode *pa = headA,*pb = headB;
            while(pa != pb)
            {
                pa = pa -> next ? pa -> next: pb;
                pb = pb -> next ? pb -> next: pa;
            }
            return pa;
        }
};


int main()
{
    return 0;
}
