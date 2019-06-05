/**
题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/

#include <iostream>
#include <vector>
using namespace std;

/**
解题思路：
1.构建一个新的链表，然后将两个链表合并加载到新的链表
 * 
 */


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1)
            return pHead2;
        if(!pHead2)
            return pHead1;
        ListNode *pNew = NULL;
        ListNode *pNtemp = NULL;
        int p1 = pHead1->val;
        int p2 = pHead2->val;
        // 先插入头结点
        if(p1 <= p2)
        {
            pNew = pHead1;
            pHead1 = pHead1 -> next;
        }
        else
        {
            pNew = pHead2;
            pHead2 = pHead2 -> next;
        }  
        pNtemp = pNew;
        while(pHead1 != NULL && pHead2 != NULL)
        {
            p1 = pHead1 -> val;
            p2 = pHead2 -> val;
            if(p1 <= p2)
            {
                // 保存后续节点
                pNtemp -> next = pHead1;
                pHead1 = pHead1 -> next;
                pNtemp = pNtemp -> next;

            }
            else
            {
                pNtemp -> next = pHead2;
                pHead2 = pHead2 -> next;
                pNtemp = pNtemp -> next;
            }
        }
        // 如果ph1没有结束
        if(pHead1 != NULL) 
        {
            // 保存后续节点
            pNtemp -> next = pHead1;
        }
        if(pHead2 != NULL)
        {
            pNtemp -> next = pHead2;
        }
        return pNew;
    
    }
    // 还有一种递归的方法,思路清晰，代码看着不清晰，不过，代码很厉害
    ListNode* Merge_0(ListNode* pHead1, ListNode* pHead2)
    {
        // 终止递归的点
        if(pHead1 == NULL){
            return pHead2;
        }
        if(pHead2 == NULL){
            return pHead1;
        }
        if(pHead1->val <= pHead2->val){
            pHead1->next = Merge_0(pHead1->next, pHead2);
            return pHead1;
        }else{
            pHead2->next = Merge_0(pHead1, pHead2->next);
            return pHead2;
        }       
    }
  
};

int main()
{

}