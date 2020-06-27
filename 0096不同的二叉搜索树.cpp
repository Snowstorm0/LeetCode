

//96. 不同的二叉搜索树
//给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
//示例 :
//输入: 3
//输出 : 5
//解释 :
//给定 n = 3, 一共有 5 种不同结构的二叉搜索树 :
//
//  1         3     3      2      1
//   \       /     /      / \      \
//    3     2     1      1   3      2
//   /     /       \                 \
//  2     1         2                 3




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



int numTrees(int n)
{
    if (n <= 0)
        return 0;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)    //有i个节点时
        for (int j = 0; j < i; j++)  //有i-1个节点为子节点，左右分别为j、i-1-j
            dp[i] = dp[i] + dp[j] * dp[i - 1 - j];

    return dp[n];
}

int main()
{
    int res = numTrees(3);
    cout << res;
    system("pause");

    return 0;
}









