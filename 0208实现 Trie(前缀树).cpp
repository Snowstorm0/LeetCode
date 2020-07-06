

//208. 实现 Trie(前缀树)
//实现一个 Trie(前缀树)，包含 insert, search, 和 startsWith 这三个操作。
//示例 :
//Trie trie = new Trie();
//trie.insert("apple");
//trie.search("apple");   // 返回 true
//trie.search("app");     // 返回 false
//trie.startsWith("app"); // 返回 true
//trie.insert("app");
//trie.search("app");     // 返回 true
//说明:
//你可以假设所有的输入都是由小写字母 a - z 构成的。
//保证所有输入均为非空字符串。




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






class Trie {
private:
    bool isEnd;
    Trie* next[26];
public:
    Trie() 
    {
        isEnd = false;
        memset(next, 0, sizeof(next));
    }

    void insert(string word) 
    {
        Trie* node = this;
        for (char s : word)
        {
            if (node->next[s - 'a'] == NULL)
                node->next[s - 'a'] = new Trie();
            node = node->next[s - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) 
    {
        Trie* node = this;
        for (char s : word)
        {
            node = node->next[s - 'a'];
            if (node == nullptr)
                return false;
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) 
    {
        Trie* node = this;
        for (char s : prefix)
        {
            node = node->next[s - 'a'];
            if (node == nullptr)
                return false;
        }
        return true;
    }
};


int main()
{
    Trie trie = Trie();
    trie.insert("apple");
    trie.search("apple");  
    trie.search("app");    
    trie.startsWith("app"); 
    trie.insert("app");
    

    bool res = trie.search("app");
    cout << res << endl;
    system("pause");

    return 0;
}








