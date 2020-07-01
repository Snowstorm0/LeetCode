

//148. 排序链表
//在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
//示例 1:
//输入: 4->2->1->3
//输出 : 1->2->3->4
//示例 2 :
//输入 : -1->5->3->4->0
//输出 : -1->0->3->4->5




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




ListNode* cut(ListNode* head, int n)
{
    while (n > 1 && head)
    {
        head = head->next;
        n--;
    }
    if (head == nullptr)
        return nullptr;
    ListNode* tmp = head->next;
    head->next = nullptr;
    return tmp;
}

ListNode* merge(ListNode* head1, ListNode* head2)
{
    ListNode* prehead = new ListNode(0);
    ListNode* p = prehead;
    while (head1 != nullptr && head2 != nullptr)
    {
        if (head1->val < head2->val)
        {
            p->next = head1;
            p = p->next;
            head1 = head1->next;
        }
        else
        {
            p->next = head2;
            p = p->next;
            head2 = head2->next;
        }
    }

    if (head1 == nullptr)
        p->next = head2;
    else
        p->next = head1;

    return prehead->next;
}



ListNode* sortList(ListNode* head)
{
    ListNode* prehead = new ListNode(0);
    prehead->next = head;

    int len = 0;
    ListNode* p = head;
    while (p != nullptr)
    {
        p = p->next;
        len++;
    }
    for (int tmplen = 1; tmplen < len; tmplen *= 2)
    {
        ListNode* tail = prehead;
        ListNode* cur = prehead->next;

        while (cur)
        {
            ListNode* left = cur;
            ListNode* right = cut(left, tmplen);
            cur = cut(right, tmplen);
            tail->next = merge(left, right);
            while (tail->next)
                tail = tail->next;
        }
    }
    return prehead->next;
}


int main()
{
    ListNode* head = new ListNode(1);
    ListNode* list = head;
    list->next = new ListNode(3);
    list = list->next;
    list->next = new ListNode(4);
    list = list->next;
    list->next = new ListNode(2);

    //print(head);
    ListNode* res = sortList(head);
    print(res);

    system("pause");

    return 0;
}


