/**

请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/

/**
解题思路：

遍历，计算长度，然后从中间部分开始插入到头部，然后计算前后是否相等
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode 
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x),next(NULL){};
};

// step1: get the mid node;
// step2: reverse the right list;
// step3: cmp left and right list.
class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            if(head == NULL || head->next == NULL) {
                return true;
            }
            
            ListNode* mid = findMid(head); // step1: get the mid node;
            ListNode* tail = reverseList(mid); // step2: reverse the right list;
            // step3: cmp left and right list.
            while(head != mid) {
                if(head->val != tail->val) {
                    return false;
                }
                
                head = head->next;
                tail = tail->next;
            }
            return true;
        }
        // 寻找到中间节点
        // 采用快慢指针的方式，一个走两步,一个走一步
        ListNode* findMid(ListNode* head) {
            if(head == NULL || head->next == NULL) {
                return head;
            }
            
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
        // 将后半部分的代码进行反转
        // 才有头插法
        ListNode* reverseList(ListNode* head) {
            if(head == NULL || head->next == NULL) {
                return head;
            }
            ListNode* pre = head;
            ListNode* cur = pre->next;
            pre->next = NULL;
            while(cur) {
                ListNode* next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            
            return pre;
        }  
};

// 才有递归的方法没有看太明白
// 但是稍微有些理解，需要一个全局的指针
class Solution_ {
    public:
        ListNode* temp;
        bool isPalindrome(ListNode* head) {
            temp = head;
            return check(head);
        }
        // 使用递归来解决问题
        // 这个递归不太会，说明递归的学习没有到家
        bool check(ListNode* p) {
            if (NULL == p) return true;
            bool isPal = check(p->next) & (temp->val == p->val);
            temp = temp->next;
            return isPal;
        }
};