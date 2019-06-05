/**
题目描述
输入两个链表，找出它们的第一个公共结点
*/

/**
解题思路：
1.朴素的想法：先计算长度，然后长链表先走一段长度差，之后同时遍历
2.参看大神的代码
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

class Solution {
public:
    // 神级代码，膜拜膜拜
    // 用两个指针扫描”两个链表“，最终两个指针到达 null 或者到达公共结点。
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while(p1!=p2){
            p1 = (p1==NULL ? pHead2 : p1->next);
            p2 = (p2==NULL ? pHead1 : p2->next);
        }
        return p1;
    }
    // 非常朴素简单的想法
    ListNode* FindFirstCommonNode_( ListNode* pHead1, ListNode* pHead2) {

        int len_0 = 0,len_1 = 0;
        ListNode *p_0 = pHead1,*p_1 = pHead2;
        while(p_0 != NULL)
        {
            ++len_0;
            p_0 = p_0 -> next;
        }
        while(p_1 != NULL)
        {
            ++len_1;
            p_1 = p_1 -> next;    
        }
        p_0 = pHead1;
        p_1 = pHead2;

        if(len_1 > len_0)
        {
            int temp = len_1 - len_0;
            while(temp-- > 0)
            {
                p_1 = p_1 -> next;
            }
        }
        else if(len_0 > len_1)
        {
            int temp = len_0 - len_1;
            while(temp-- > 0)
            {
                p_0 = p_0 -> next;
            }
        }
        // 并行遍历
        while(p_0 != p_1)
        {
            p_0 = p_0 -> next;
            p_1 = p_1 -> next;
        }
        return p_0;
    }
};
