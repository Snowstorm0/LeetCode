

//104. 二叉树的最大深度
//给定一个二叉树，找出其最大深度。
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//说明 : 叶子节点是指没有子节点的节点。
//示例：
//给定二叉树[3, 9, 20, null, null, 15, 7]，
//      3
//     / \
//    9  20
//       / \
//     15   7
//返回它的最大深度 3 




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


int maxDepth(TreeNode* root)
{
    if (root == nullptr)
        return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}


int main()
{
    TreeNode tree = TreeNode(2);
    TreeNode* result;

    result = insert(&tree, 1);
    result = insert(&tree, 4);
    result = insert(&tree, 7);
    result = insert(&tree, 4);
    result = insert(&tree, 8);
    result = insert(&tree, 3);
    result = insert(&tree, 6);
    result = insert(&tree, 7);
    result = insert(&tree, 4);

    //output(result);        


    int res = maxDepth(result);
    cout << res;

    system("pause");

    return 0;
}









