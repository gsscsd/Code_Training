/**
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
*/

/**
解题思路：
快慢指针+虚拟头结点
*/


#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 没有头结点，加上头节点
        // 通过增加虚拟头结点的方法，可以用来避免，需要删除头结点的问题
        ListNode *vhead = new ListNode(0);
        vhead->next = head;
        ListNode *pre = vhead;
        ListNode *next = vhead;
        // next先走n步
        // 然后pre和next一起走
        while (n--)
        {
            next = next->next;
        }
        while (next->next)
        {
            next = next->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return vhead->next;
    }
};

// 不加虚拟指针的解决方法
class Solution_0
{
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 如果只有一个头结点，那么直接删除头结点
        if (!head->next)
            return NULL;
        ListNode *first = head;
        ListNode *second = head;
        while (n > 0)
        {
            second = second->next;
            n--;
        }
        // 删除了头结点，保留剩下的节点
        if (!second)
        {
            return head->next;
        }
        while (second->next)
        {
            first = first->next;
            second = second->next;
        }
        first->next = first->next->next;
        return head;
    }
};
// 使用vector来保留节点
class Solution_1
{
  public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head->next && n == 1)
            return NULL;
        vector<ListNode *> v;
        ListNode *probe = head;
        while (probe)
        {
            v.push_back(probe);
            probe = probe->next;
        }
        if (n == 1)
            v[v.size() - 2]->next = NULL;
        else if (n == v.size())
            head = head->next;
        else
            v[v.size() - n - 1]->next = v[v.size() - n + 1];
        return head;
    }
};
