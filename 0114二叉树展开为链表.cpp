

//114. 二叉树展开为链表
//给定一个二叉树，原地将它展开为一个单链表。
//例如，给定二叉树
//        1
//       / \
//      2   5
//     / \   \
//    3   4   6
//将其展开为：
//
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6




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



//先递归将每一颗子树均整合成只有右子树的形式
//再将右子树插入左子树的末尾节点，将左子树插入root的右子树部分
//将root的左子树置为空，再返回root


TreeNode* build(TreeNode* root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return root;
    root->left = build(root->left);
    root->right = build(root->right);
    if (root->left == nullptr)
        return root;

    TreeNode* p = root->left;

    while (p->right != nullptr)
    {
        p = p->right;
    }
    p->right = root->right;
    root->right = root->left;
    root->left = nullptr;

    return root;
}


void flatten(TreeNode* root)
{
    root = build(root);
    return;
}

int main()
{
    TreeNode tree = TreeNode(1);
    TreeNode* result;

    result = insert(&tree, 3);
    result = insert(&tree, 2);

    //output(result);

    flatten(result);
    output(result);

    system("pause");

    return 0;
}







