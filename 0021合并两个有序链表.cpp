

//21. 合并两个有序链表
//将两个升序链表合并为一个新的 升序 链表并返回。
//新链表是通过拼接给定的两个链表的所有节点组成的。
//示例：
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4






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



ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;

    ListNode* res = new ListNode(0);
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    ListNode* p = res;

    while (l1 != nullptr || l2 != nullptr)
    {
        if (p1 == nullptr)
        {
            p->next = p2;
            break;
        }
        if (p2 == nullptr)
        {
            p->next = p1;
            break;
        }

        if (p1->val > p2->val)
        {
            p->next = new ListNode(p2->val);
            p2 = p2->next;
            p = p->next;
        }
        else
        {
            p->next = new ListNode(p1->val);
            p1 = p1->next;
            p = p->next;
        }
    }
    return res->next;

}





int main()
{

    ListNode* head1 = new ListNode(1);
    ListNode* list1 = head1;
    list1->next = new ListNode(2);
    list1 = list1->next;
    list1->next = new ListNode(4);

    ListNode* head2 = new ListNode(1);
    ListNode* list2 = head2;
    list2->next = new ListNode(3);
    list2 = list2->next;
    list2->next = new ListNode(4);

    //print(head);
    //system("pause");

    ListNode* restlt = mergeTwoLists(head1, head2);
    print(restlt);
    system("pause");

    return 0;

}

