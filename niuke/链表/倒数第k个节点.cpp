/**
题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 */
#include <iostream>
#include <vector>
using namespace std;


/**
解题思路：
1.两个指针，先让第一个指针和第二个指针都指向头结点，然后再让第一个指正走(k-1)步，
到达第k个节点。然后两个指针同时往后移动，当第一个结点到达末尾的时候，第二个结点所在位置就是倒数第k个节点了
2.两次for循环，第一次统计长度，第二次计算节点
 * 
 * 
 */

typedef struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
} ListNode;


class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        int count = 0;
        ListNode* pre = pListHead;
        ListNode* last = pListHead;
    
        // 一开始就进行边界检测
        if(pListHead == NULL || k <= 0)
        {
            return 0;
        }
        // 这里为啥是从1开始到k呢(其实进行了k-1次),为啥不是0呢.
        // 修改为从0开始
        for(int i = 0;i < k - 1;i++)
        {
            // 判断是否有下一个节点
            if(pre -> next != NULL)
            {
                pre = pre->next;
            }
            else
            {
                return NULL;
            }
        }
        // 注意这里的边界检测
        while(pre->next != NULL)
        {
            pre = pre->next;
            last = last->next;
        }
        return last;
    }
    // 一个更简洁的代码
     ListNode* FindKthToTail_(ListNode* pListHead, unsigned int k) {
         ListNode *p,*q;
         p = q = pListHead;
         int i = 0;
         for(;p != NULL;i++)
         {
            //  注意这些小的边界条件
             if(i >= k) q = q-> next;
             p = p -> next;
         }
         return i < k ? NULL:p;
    }
};

int main()
{

}