
//2.两数相加
//给出两个 非空 的链表用来表示两个非负的整数。其中，
//它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807



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
    ListNode *next;  //指向下一个结点的指针用next表示
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



ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode* head = new ListNode(0);
    ListNode* res = head;
    if (l1 == nullptr || l2 == nullptr)
        return res;

    int sum = 0;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr)
    {
        if (l1 != nullptr)  //为空相当于高位为0
        {
            sum = sum + l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr)
        {
            sum = sum + l2->val;
            l2 = l2->next;
        }

        sum = sum + carry;
        if (sum >= 10)
            carry = 1;
        else
            carry = 0;
        res->next = new ListNode(sum % 10);
        sum = 0;
        res = res->next;

    }
    if(carry == 1)
        res->next = new ListNode(1);
    return head->next;

}



int main()
{
    ListNode* listnode1 = new ListNode(0);

    ListNode* listnode2 = new ListNode(7);
    listnode2->next = new ListNode(3);

    print(listnode1);
    cout << endl;
    print(listnode2);
    cout << endl;

    ListNode* restlt = addTwoNumbers(listnode1, listnode2);


    print(restlt);
    system("pause");
    
    return 0;
}




