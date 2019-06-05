/**
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:
输入: 1->1->2
输出: 1->2

示例 2:
输入: 1->1->2->3->3
输出: 1->2->3
*/

/**
解题思路：
剑指offer的原题
1.递归
2.迭代计算
*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
public:
    // 自己的代码还是有点冗余，可以进行优化
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pHead = head;
        ListNode *pTemp = head;
        while(pTemp != NULL && pTemp -> next != NULL)
        {
            // 判断当前元素和下一个元素是否相等
            // 如果相等，则进入下一个while去遍历找到不等的节点
            if(pTemp -> val == pTemp -> next -> val)
            {
                ListNode *pN = pTemp;
                while(pN != NULL && pN -> val == pTemp -> val)
                {
                    pN = pN -> next;
                }
                pTemp -> next = pN;
                pTemp = pTemp -> next;
            }
            else pTemp = pTemp -> next;
        }
        return pHead;
    }
    // 观察高票的优化答案
    ListNode* deleteDuplicates_(ListNode* head)
    {
        ListNode *pHead = head;
        ListNode *pTemp = head;
        // 边界判断
        if (!head || !head->next) return head;
        while(pTemp && pTemp -> next)
        {
            if(pTemp -> val == pTemp -> next -> val)
            {
                // 将当前节点保存，并删除
                ListNode *pN = pTemp -> next;
                pTemp -> next = pTemp -> next -> next;
                delete pN;
            }
            else pTemp = pTemp -> next;
        }
        return pHead;
    }
};

int main()
{
    return 0;
}