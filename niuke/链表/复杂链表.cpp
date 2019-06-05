/**
题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/


/***
解题思路：
1.三步法:
    1、遍历链表，复制每个结点，如复制结点A得到A1，将结点A1插到结点A后面；
    2、重新遍历链表，复制老结点的随机指针给新结点，如A1.random = A.random.next;
    3、拆分链表，将链表拆分为原链表和复制后的链表
* **/



#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};


class Solution {
public:
    // 三步法操作
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        RandomListNode *currNode = pHead;
        // 1.在原来的链表上复制一个节点并插在原来节点的后面
        while(currNode)
        {
            RandomListNode *node = new RandomListNode(currNode -> label);
            node -> next = currNode -> next;
            currNode -> next = node ;
            // 这里是跳过复制的节点
            currNode = currNode -> next -> next;
        }
        // 2.重新遍历节点，复制老结点的随机指针给新结点
        currNode = pHead;
        while(currNode)
        {
            // 找到复制的节点，修复random指针
            RandomListNode *node = currNode -> next;
            if(currNode -> random)
            {
                // 注意后面currNode -> random -> next 这里的next是因为，复制的节点在原节点的后面
                node -> random = currNode -> random -> next;
            }
            // 每次来遍历下一个节点,
            currNode = node -> next;
        }
        // 拆分节点
        RandomListNode *pCloneHead = pHead -> next;
        // 用temp来保存复制后的节点,不太理解如何拆分的,画个图就明白了，
        RandomListNode * temp;
        currNode = pHead;
        // 边界条件
        while(currNode -> next)
        {
            // 这里是从头结点开始，每次跳一个节点去链接
            temp = currNode->next;
            currNode -> next = temp -> next;
            currNode = temp;
        }
        return pCloneHead;

    }

    // 以下也是三步法，不过是通过三个函数，一步一个函数来操作的，比较清晰一些。
    //1. 复制原始链表的任一节点N并创建新节点N'，再把N'链接到N的后边
    void CloneNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode=pHead;
        while(pNode!=NULL)
        {
            RandomListNode* pCloned=new RandomListNode(0);
            pCloned->label = pNode->label;
            pCloned->next = pNode->next;
            pCloned->random =NULL;
              
            pNode->next = pCloned;
              
            pNode = pCloned->next;
        }
    }
    //2. 如果原始链表上的节点N的random指向S，则对应的复制节点N'的random指向S的下一个节点S'
    void ConnectRandomNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode=pHead;
        while(pNode!=NULL)
        {
            RandomListNode* pCloned=pNode->next;
            if(pNode->random!=NULL)
                pCloned->random = pNode->random->next;
            pNode=pCloned->next;
        }
    }
    //3.把得到的链表拆成两个链表，奇数位置上的结点组成原始链表，偶数位置上的结点组成复制出来的链表
    // 这个拆分函数比较清晰，构造一个新的链表来指向复制节点
    RandomListNode* ReConnectNodes(RandomListNode* pHead)
    {
        RandomListNode* pNode = pHead;
        RandomListNode* pClonedHead=NULL;
        RandomListNode* pClonedNode=NULL;
          
        //初始化
        if(pNode!=NULL)
        {
            pClonedHead = pClonedNode = pNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;      
        }
        //循环
        while(pNode!=NULL)
        {
            pClonedNode->next = pNode->next;
            pClonedNode = pClonedNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
          
        return pClonedHead;
          
    }
    //三步合一
    RandomListNode* Clone_(RandomListNode* pHead)
    {
        CloneNodes(pHead);
        ConnectRandomNodes(pHead);
        return ReConnectNodes(pHead);
    }
};

int main()
{

}