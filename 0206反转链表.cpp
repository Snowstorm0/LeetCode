

//206. 反转链表
//反转一个单链表。
//示例 :
//输入: 1->2->3->4->5->NULL
//输出 : 5->4->3->2->1->NULL
//进阶 :
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题？




#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack> 
#include <map> 
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;


struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void print(ListNode *head)
{
    ListNode *p = head;
    while (p != NULL)
    {
        cout << p->val;
        p = p->next;
    }
}




ListNode* reverseList(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    
    ListNode* tmp = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return tmp;
}



int main()
{
    ListNode* head = new ListNode(1);
    ListNode* list = head;
    list->next = new ListNode(2);
    list = list->next;
    list->next = new ListNode(3);
    list = list->next;
    list->next = new ListNode(4);

    //print(head);
    //system("pause");

    ListNode* res = reverseList(head);
    print(res);
    system("pause");

    return 0;
}





