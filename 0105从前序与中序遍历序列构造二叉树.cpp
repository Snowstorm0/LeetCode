

//105. 从前序与中序遍历序列构造二叉树
//根据一棵树的前序遍历与中序遍历构造二叉树。
//注意 :
//你可以假设树中没有重复的元素。
//例如，给出
//前序遍历 preorder = [3, 9, 20, 15, 7]
//中序遍历 inorder = [9, 3, 15, 20, 7]
//返回如下的二叉树：
//    3
//   / \
//  9  20
//     / \
//   15   7




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




TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    if (preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size())
        return nullptr;

    vector<int> leftpre;
    vector<int> leftin;
    vector<int> rightpre;
    vector<int> rightin;

    int len = preorder.size();
    int val = preorder[0];
    int leftlen;
    for (int i = 0; i < len; i++)
    {
        if (inorder[i] == val)
        {
            leftlen = i;
            break;
        }
    }

    for (int i = 0; i < leftlen; i++)
    {
        leftin.push_back(inorder[i]);
        leftpre.push_back(preorder[i + 1]);
    }
    for (int i = leftlen + 1; i < len; i++)
    {
        rightin.push_back(inorder[i]);
        rightpre.push_back(preorder[i]);
    }

    TreeNode* root = new TreeNode(val);
    root->left = buildTree(leftpre, leftin);
    root->right = buildTree(rightpre, rightin);

    return root;
}



int main()
{
    vector<int> preorder = { 3, 9, 20, 15, 7 };
    vector<int> inorder = { 9, 3, 15, 20, 7 };


    TreeNode* res = buildTree(preorder, inorder);
    output(res);

    system("pause");

    return 0;
}







