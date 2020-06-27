

//64. 最小路径和
//给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，
//使得路径上的数字总和为最小。
//说明：每次只能向下或者向右移动一步。
//示例 :
//输入:
//[
//    [1, 3, 1],
//    [1, 5, 1],
//    [4, 2, 1]
//]
//输出 : 7
//解释 : 因为路径 1→3→1→1→1 的总和最小。






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


int minPathSum(vector<vector<int>>& grid)
{
    int len = grid.size();
    int len1 = grid[0].size();

    vector<vector<int>> sum(len, vector<int>(len1, 0));

    sum[0][0] = grid[0][0];
    for (int i = 1; i < len1; i++)    //只有一行或一列时，只有一种走法
        sum[0][i] = sum[0][i-1] + grid[0][i];

    for (int i = 1; i < len; i++)
        sum[i][0] = sum[i-1][0] + grid[i][0];

    for(int i=1;i<len;i++)
        for (int j = 1; j < len1; j++)
            sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];


    return sum[len - 1][len1 - 1];
}

int main()
{
    vector<vector<int>> vec = { { 1, 2, 5 },{ 3, 2, 1 }};
    int res = minPathSum(vec);
    cout << res <<  endl;
    system("pause");

    return 0;
}

















