/**
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.
*/
/**
解题思路：
递归
使用递归来解决该题，主要就是递归的三部曲：

找终止条件：本题终止条件很明显，当递归到链表为空或者链表只剩一个元素的时候，没得交换了，自然就终止了。
找返回值：返回给上一层递归的值应该是已经交换完成后的子链表。
单次的过程：因为递归是重复做一样的事情，所以从宏观上考虑，只用考虑某一步是怎么完成的。
我们假设待交换的俩节点分别为head和next，next的应该接受上一级返回的子链表(参考第2步)。
就相当于是一个含三个节点的链表交换前两个节点，就很简单了，想不明白的画画图就ok。
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){};
};

class Solution
{
  public:
    ListNode *swapPairs(ListNode *head)
    {
        // 注意这里的递归出口
        if (!head || !head->next)
            return head;

        ListNode *temp = head->next;
        head->next = swapPairs(temp->next);
        temp->next = head;
        return temp;
    }
};