/**
 * 
题目描述
输入一个链表，反转链表后，输出新链表的表头。
 * 
 */

#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

/**
 * 
解题思路：
1.新链表，头插法。
 * 
 */

typedef struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
}ListNode;
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL) return NULL;//注意程序鲁棒性
        // 定义中间节点
        ListNode *pNew = NULL;
        ListNode *p_old = NULL;
        ListNode *pNode = pHead;
        
        while(pNode != NULL)
        {
            // 保存断掉的后面的链表节点
            ListNode *p_temp = pNode -> next;
            // 如果后面的链表为NULL，则说明当前节点是尾节点
            // if(p_temp == NULL)
            // {
            //     pNew = pNode;
            // }
            // 指定当前节点的下一个节点
            // 头插法
            p_old = pNode;
            p_old -> next = pNew;
            pNew = p_old;
            // // 另一种指针反转的方法
            // pNode -> next = p_old;
            // p_old = pNode;
            pNode = p_temp;

        }
        return pNew;
    }
};

int main()
{

}