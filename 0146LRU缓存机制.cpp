

//146. LRU缓存机制
//运用你所掌握的数据结构，设计和实现一个  
//LRU(最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
//获取数据 get(key) - 如果关键字(key) 存在于缓存中，
//则获取关键字的值（总是正数），否则返回 - 1。
//写入数据 put(key, value) - 如果关键字已经存在，则变更其数据值；
//如果关键字不存在，则插入该组「关键字 / 值」。当缓存容量达到上限时，
//它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
//进阶 :
//你是否可以在 O(1) 时间复杂度内完成这两种操作？
//示例 :
//LRUCache cache = new LRUCache(2 /* 缓存容量 */);
//cache.put(1, 1);
//cache.put(2, 2);
//cache.get(1);       // 返回  1
//cache.put(3, 3);    // 该操作会使得关键字 2 作废
//cache.get(2);       // 返回 -1 (未找到)
//cache.put(4, 4);    // 该操作会使得关键字 1 作废
//cache.get(1);       // 返回 -1 (未找到)
//cache.get(3);       // 返回  3
//cache.get(4);       // 返回  4




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



struct ListNode2
{
    int key;
    int val;
    ListNode2* pre;
    ListNode2* next;
    ListNode2(int x, int y):key(x),val(y),pre(nullptr),next(nullptr){}
};

class LRUCache 
{

private:
    int len;
    ListNode2* head;
    ListNode2* tail;
    unordered_map<int, ListNode2*> umap;

public:
    LRUCache(int capacity) 
    {
        this->len = capacity;
        this->head = nullptr;
        this->tail = nullptr;
    }

    int get(int key) 
    {
        if (umap.find(key) != umap.end())
        {
            remove(umap[key]);
            setHead(umap[key]);
            return umap[key]->val;
        }
        return -1;
    }

    void put(int key, int value) 
    {
        if (umap.find(key) != umap.end())
        {
            umap[key]->val = value;
            remove(umap[key]);
            setHead(umap[key]);
        }
        else
        {
            if (umap.size() >= this->len)
            {
                umap.erase(tail->key);
                remove(tail);
            }
            ListNode2* tmpnode = new ListNode2(key, value);
            setHead(tmpnode);
            umap[key] = tmpnode;
        }

    }

    void remove(ListNode2* node) 
    {
        if (node == head)
            head = head->next;
        else if (node == tail)
            tail = tail->pre;
        else {
            node->pre->next = node->next;
            node->next->pre = node->pre;
        }

    }

    void setHead(ListNode2* node) 
    {
        if (head == nullptr && tail == nullptr) 
        {
            head = node;
            tail = node;
        }
        else 
        {
            node->next = head;
            if (head != nullptr)
                head->pre = node;
            head = node;
        }
    }
};

int main()
{
    LRUCache cache =  LRUCache(2);
    cache.put(1, 1);
    cache.put(2, 2); 
    cache.get(1);
    cache.put(3, 3);

    int res = cache.get(2);     
    cout << res << endl;
    system("pause");

    return 0;
}


