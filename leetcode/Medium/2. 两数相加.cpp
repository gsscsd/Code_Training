/**
给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，
它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/


/**
解题思路：
好好看一下，leetcode的高票答案，非常巧妙，很值得学习，对齐节点 
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

            ListNode *pHead = new ListNode(-1);
            if(!l1) pHead -> next = l2;
            if(!l2) pHead -> next = l1;
            ListNode *pH = pHead;
            int flag = 0;
            while(l1 || l2 || flag)
            {
                        // 判断当前的节点是否为NULL
                        int sum = (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0) + flag;
                        // 用来判断是否大于10，然后去加在下一个节点
                        flag = sum / 10;
                        pH->next = new ListNode(sum % 10);
                        pH = pH -> next;
                        // 这里的处理很巧啊
                        // 判断下一个节点是否存在，如果不存在就用第一个为NULL的节点
                        l1 = l1 ? l1->next : l1;
                        l2 = l2 ? l2->next : l2;
            }
            return pHead -> next;
    }
};