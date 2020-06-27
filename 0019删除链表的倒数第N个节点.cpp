

//19. 删除链表的倒数第N个节点
//给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
//示例：
//给定一个链表 : 1->2->3->4->5, 和 n = 2.
//    当删除了倒数第二个节点后，链表变为 1->2->3->5.
//    说明：
//    给定的 n 保证是有效的。
//    进阶：
//    你能尝试使用一趟扫描实现吗？






#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <iostream>
#include <stack> 
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;



struct ListNode                 //定义一个结构体  ListNode的结构
{
    int val;                  //当前结点的值用val表示
    struct ListNode *next;  //指向下一个结点的指针用next表示
    ListNode(int x) : val(x), next(NULL) { } //初始化当前结点值为x,指针为空
};

void print(ListNode *head)   //打印输出链表
{
    ListNode *p = head;
    while (p != NULL)
    {
        cout << p->val;
        p = p->next;
    }
}






ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    ListNode* res = new ListNode(0);
    if (head == nullptr || n <= 0)
        return head;

    ListNode* left = head;
    ListNode* right = head;
    for (int i = 0; i < n; i++)
    {
        right = right->next;
    }
    if (right == nullptr)
        return head->next;
    while (right->next != nullptr)
    {
        left = left->next;
        right = right->next;
    }
    left->next = left->next->next;

    return head;
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

    ListNode* restlt = removeNthFromEnd(head, 2);
    print(restlt);
    system("pause");

    return 0;
}



