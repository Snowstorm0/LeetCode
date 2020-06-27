

//94. 二叉树的中序遍历
//给定一个二叉树，返回它的中序 遍历。
//示例 :
//输入: [1, null, 2, 3]
//    1
//    \
//    2
//    /
//    3
//
//输出: [1, 3, 2]
//进阶 : 递归算法很简单，你可以通过迭代算法完成吗？




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

struct TreeNode         // 定义二叉树
{
    int val;             // 当前节点值用val表示
    TreeNode *left;      // 指向左子树的指针用left表示
    TreeNode *right;     // 指向右子树的指针用right表示
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }    // 初始化当前结点值为x,左右子树为空
};


TreeNode* insert(TreeNode* tree, int value)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); // 创建一个节点
    node->val = value;      // 初始化节点
    node->left = NULL;
    node->right = NULL;

    TreeNode* temp = tree;      // 从树根开始
    while (temp != NULL)
    {
        if (value < temp->val)  // 小于就进左儿子
        {
            if (temp->left == NULL)
            {
                temp->left = node;
                return tree;
            }
            else {        
                temp = temp->left;
            }
        }
        else {            

            if (temp->right == NULL)
            {
                temp->right = node;
                return tree;
            }
            else {          
                temp = temp->right;
            }
        }
    }
    return tree;
}

void output_impl(TreeNode* n, bool left, string const& indent)
{
    if (n->right)
    {
        output_impl(n->right, false, indent + (left ? "|     " : "      "));
    }
    cout << indent;
    cout << (left ? '\\' : '/');
    cout << "-----";
    cout << n->val << endl;
    if (n->left)
    {
        output_impl(n->left, true, indent + (left ? "      " : "|     "));
    }
}
void output(TreeNode* root)
{
    if (root->right)
    {
        output_impl(root->right, false, "");
    }
    cout << root->val << endl;
    if (root->left)
    {
        output_impl(root->left, true, "");
    }
    system("pause");
}


//1.将整棵树的最左边一条链压入栈中
//2.每次取出栈顶元素，如果它有右子树，则将右子树压入栈中。


vector<int> inorderTraversal(TreeNode* root)
{
    if (root == nullptr)
        return{};

    vector<int> res;
    stack<TreeNode*> sta;
    TreeNode* p = root;
    while (p != nullptr || !sta.empty())
    {
        while (p != nullptr)
        {
            sta.push(p);
            p = p->left;
        }

        p = sta.top();
        sta.pop();
        res.push_back(p->val);
        p = p->right;
    }

    return res;
}




int main()
{
    vector<int> res;
    TreeNode tree = TreeNode(10);  
    TreeNode* result;

    result = insert(&tree, 6);    
    result = insert(&tree, 4);
    result = insert(&tree, 8);
    result = insert(&tree, 14);
    result = insert(&tree, 12);
    result = insert(&tree, 16);

    //output(result);        

    res = inorderTraversal(result);
    for (int i = 0; i < res.size(); i++)
        cout << res[i];
    system("pause");

    return 0;
}









