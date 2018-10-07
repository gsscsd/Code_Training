/**
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

/**
解题思路：
1.最简单的去遍历
2.递归运算 
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


typedef struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
}ListNode;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode *p;
            
            if(!l1) return l2;
            if(!l2) return l1;
           if(l1->val <= l2 -> val)
           {
                   p = l1;
                   l1 = l1->next;
           }
           else
           {
                   p = l2;
                   l2 = l2->next;
           }
           ListNode *pHead = p;
           while(l1 && l2)
           {
                   if(l1 ->val <= l2 ->val)
                   {
                           p->next = l1;
                           l1 = l1->next;
                   }
                   else
                   {
                           p->next = l2;
                           l2 = l2->next;
                   }
                   p = p->next;
           }
           if(!l1) p->next = l2;
           else p->next = l1;
           return pHead;
    }
        // 大神的递归运算,时间更快一些
        // 这种思路需要好好学习，本来以为递归的时间复杂度会更高呢，
        // 代码更加简洁
        ListNode* mergeTwoLists_(ListNode* l1, ListNode* l2) {
                // 递归的边界
                if(l1==NULL)
                        return l2;
                if(l2==NULL)
                        return l1;
                ListNode* head=NULL;
                // 递归体
                if(l1->val > l2->val){
                        head=l2;
                        head->next = mergeTwoLists(l1,l2->next);
                }
                else{
                        head = l1;
                        head->next=mergeTwoLists(l1->next,l2);
                }
                // 递归返回
                return head;
        }
};


int main()
{

        return 0;

}

