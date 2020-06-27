

//102. 二叉树的层序遍历
//给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 
//（即逐层地，从左到右访问所有节点）。
//示例：
//二叉树：[3, 9, 20, null, null, 15, 7],
//     3
//    / \
//   9  20
//  / \
// 15   7
//返回其层次遍历结果：
//
//[
//    [3],
//    [9, 20],
//    [15, 7]
//]




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



vector<vector<int>> levelOrder(TreeNode* root)
{
    if (root == nullptr)
        return{};

    vector<vector<int>>res;
    vector<int> tmp;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty())
    {
        int len = que.size();
        for (int i = 0; i < len; i++)
        {
            TreeNode* p = que.front();
            que.pop();
            tmp.push_back(p->val);
            if (p->left)
                que.push(p->left);
            if (p->right)
                que.push(p->right);
        }
        res.push_back(tmp);
        tmp.clear();
    }

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


    vector<vector<int>> res = levelOrder(result);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j<res[i].size(); j++)
            cout << res[i][j];
        cout << endl;
    }

    system("pause");

    return 0;
}









