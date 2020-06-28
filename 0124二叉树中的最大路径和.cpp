

//124. 二叉树中的最大路径和
//给定一个非空二叉树，返回其最大路径和。
//本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。
//该路径至少包含一个节点，且不一定经过根节点。
//示例 1:
//输入: [1, 2, 3]
//
//      1
//     / \
//    2   3
//
//输出: 6




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







int maxPathSum(TreeNode* root, int &res)
{
    if (root == nullptr)
        return 0;
    int leftres = maxPathSum(root->left, res);
    int rightres = maxPathSum(root->right, res);
    int left = max(leftres, 0);
    int right = max(rightres, 0);
    int tmp = left + root->val + right;

    res = max(res, tmp);

    return root->val + max(left, right);
}
int maxPathSum(TreeNode* root)
{
    if (root == nullptr)
        return 0;

    int res = INT_MIN;
    maxPathSum(root, res);
    return res;
}



int main()
{
    TreeNode tree = TreeNode(1);
    TreeNode* result;

    result = insert(&tree, 3);
    result = insert(&tree, 2);
    //output(result);

    int res = maxPathSum(result);
    cout << res << endl;
    system("pause");

    return 0;
}







