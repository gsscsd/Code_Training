/**
给定一个链表，判断链表中是否有环。

进阶：
你能否不使用额外空间解决此题？
*/

/**
解题思路：
剑指offer原题
快慢指针
*/

#include <iostream>
#include <vector>
#include <stirng>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x),next(NULL){}
};

class Solution
{
    public :
        bool hasCycle(ListNode *head)
        {
            if(!head || !head -> next) return false;
            ListNode *pfast = head -> next;
            ListNode *plow = head;
            while(pfast != plow)
            {
                // 一直检查快指针是否到了尽头
                if(!pfast || !pfast -> next) return false;
                pfast = pfast -> next -> next;
                plow = plow -> next;
            }
            return true;
        }
};


int main(int argc, char const *argv[])
{
    
    return 0;
}
