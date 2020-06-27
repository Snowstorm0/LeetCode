

//23. 合并K个排序链表
//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
//示例 :
//输入:
//    1->4->5,
//    1->3->4,
//    2->6
//输出 : 1->1->2->3->4->4->5->6







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





ListNode* merge(ListNode* head1, ListNode* head2)
{
    if (head1 == nullptr)
        return head2;
    if (head2 == nullptr)
        return head1;

    if (head1->val < head2->val)
    {
        head1->next = merge(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = merge(head2->next, head1);
        return head2;
    }

}
ListNode* merge2Lists(vector<ListNode*>& lists, int sta, int end)
{
    if (sta == end)
        return lists[sta];

    ListNode* l1 = merge2Lists(lists, sta, (sta + end) / 2);
    ListNode* l2 = merge2Lists(lists, (sta + end) / 2 + 1, end);

    return merge(l1, l2);
}

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    int len = lists.size();
    if (len <= 0)
        return nullptr;

    return merge2Lists(lists, 0, len - 1);
}

int main()
{
    ListNode* head1 = new ListNode(1);
    ListNode* list1 = head1;
    list1->next = new ListNode(4);
    list1 = list1->next;
    list1->next = new ListNode(5);

    ListNode* head2 = new ListNode(1);
    ListNode* list2 = head2;
    list2->next = new ListNode(3);
    list2 = list2->next;
    list2->next = new ListNode(4);

    ListNode* head3 = new ListNode(2);
    ListNode* list3 = head3;
    list3->next = new ListNode(6);

    vector<ListNode*> lists = { head1, head2, head3 };
    //print(head);
    //system("pause");

    ListNode* restlt = mergeKLists(lists);
    print(restlt);
    system("pause");

    return 0;

}






