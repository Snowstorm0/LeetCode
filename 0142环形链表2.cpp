

//142. 环形链表 II
//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置
//（索引从 0 开始）。 如果 pos 是 - 1，则在该链表中没有环。
//说明：不允许修改给定的链表。
//示例 1：
//输入：head = [3, 2, 0, -4], pos = 1
//输出：tail connects to node index 1
//解释：链表中有一个环，其尾部连接到第二个节点。




#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack> 
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

void print(ListNode *head)   //打印输出链表
{
    ListNode *p = head;
    while (p != NULL)
    {
        cout << p->val;
        p = p->next;
    }
}


ListNode *detectCycle(ListNode *head)
{
    if (head == nullptr)
        return nullptr;

    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
            fast = fast->next;
        else
            return nullptr;
        slow = slow->next;

        if (fast == slow)
        {
            fast = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    }
    return nullptr;
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

    ListNode* res = detectCycle(head);
    print(res);

    system("pause");

    return 0;
}







