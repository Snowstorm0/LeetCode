

//98. 验证二叉搜索树
//给定一个二叉树，判断其是否是一个有效的二叉搜索树。
//假设一个二叉搜索树具有如下特征：
//节点的左子树只包含小于当前节点的数。
//节点的右子树只包含大于当前节点的数。
//所有左子树和右子树自身必须也是二叉搜索树。
//示例 1:
//输入:
//    2
//   / \
//  1   3
//输出: true




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






bool dfs(TreeNode* root, long max, long min)
{
    if (root == nullptr)
        return true;
    if (root->val > max || root->val < min)//为了防止根节点等于INT_MIN或INT_MAX，所以不用>=或<=
        return false;

    return dfs(root->left, root->val - 1l, min) && dfs(root->right, max, root->val + 1l);
    //1l即long类型的1，强制转换为long
}


bool isValidBST(TreeNode* root)
{
    if (root == nullptr)
        return true;

    bool res = dfs(root, INT_MAX, INT_MIN);
    return res;
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


    bool res = isValidBST(result);
    cout << res;
    system("pause");

    return 0;
}









