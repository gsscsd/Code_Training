/**
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

/**
解题思路：
1.递归处理,牛客网高票答案
2.迭代处理,牛客网高票答案
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
  public:
    // 通过递归来实现
    ListNode *deleteNode(ListNode *pHead)
    {
        // 定义递归边界
        if (!pHead)
            return NULL;
        if (pHead != NULL && pHead->next == NULL)
            return pHead;
        ListNode *current;
        // 找到第一个开始重复的位置
        if (pHead->next->val == pHead->val)
        {
            // 首先循环的找到重复的部分，并且跳过去
            current = pHead->next->next;
            while (current != NULL && current->val == pHead->val)
            {
                current = current->next;
            }
            // 接着递归计算不重复的地方
            return deleteNode(current);
        }
        // 如果不重复
        else
        {
            // 节点后移，然后在递归计算
            current = pHead->next;
            pHead->next = deleteNode(current);
            return pHead;
        }
    }
    ListNode *deleteDuplication(ListNode *pHead)
    {
        if (!pHead)
            return NULL;
        ListNode *pNew = deleteNode(pHead);
        return pNew;
    }

    ListNode *deleteDuplication(ListNode *pHead)
    {
        // 首先创建一个头节点
        ListNode *head = new ListNode(0);
        // 接着定义两个前后指针
        // 慢指针
        ListNode *p = head;
        // 向后遍历的指针
        ListNode *q = pHead;
        // 如果q，向后遍历的指针不为空
        while (q)
        {
            // 如果Q不为空，并且Q的后续不为空，并且后续的值和当前的值是一样的话
            while (q != NULL && q->next != NULL && q->next->val == q->val)
            {
                int tmp = q->val;
                // 一直向后遍历，直到找到不同的节点
                while (q != NULL && q->val == tmp)
                    q = q->next;
            }
            // 此时慢指针添加这个不相同的节点
            p->next = q;
            // 慢指针后移
            p = p->next;
            // 如果后向节点不为空，后向节点后移
            if (q)
                q = q->next;
        }
        return head->next;
    }

    void transList(ListNode *pHead)
    {
        ListNode *ptemp = pHead;
        while (ptemp != NULL)
        {
            cout << ptemp->val << endl;
            ptemp = ptemp->next;
        }
    }
};

int main(int argc, char const *argv[])
{
    ListNode *p = new ListNode(-1);
    p->next = NULL;
    ListNode *pHead = p;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(4);
    vec.push_back(5);
    for (int i = 0; i < vec.size(); i++)
    {
        ListNode *temp = new ListNode(vec[i]);
        temp->next = NULL;
        p->next = temp;
        p = p->next;
    }
    Solution s;
    cout << "befor delete is " << endl;
    s.transList(pHead->next);
    cout << "after delete is " << endl;
    ListNode *tt = s.deleteDuplication(pHead->next);
    s.transList(tt);

    return 0;
}
