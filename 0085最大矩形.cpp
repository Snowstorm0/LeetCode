

//85. 最大矩形
//给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
//示例 :
//输入:
//[
//    ["1", "0", "1", "0", "0"],
//    ["1", "0", "1", "1", "1"],
//    ["1", "1", "1", "1", "1"],
//    ["1", "0", "0", "1", "0"]
//]
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


//heights[i][j]代表[i，j]的高度
//heights[i][j] = matrix[i][j] == '1' ? heights[i - 1][j] + 1 : 0
//
//dp[i][j][k] 代表以[i, j]为右下角，高度为k可以组成的面积
//dp[i][j][k] = dp[i][j - 1][k] + k

int maximalRectangle(vector<vector<char>>& matrix)
{
    int row = matrix.size();
    if (row <= 0)
        return 0;
    int col = matrix[0].size();
    if (col <= 0)
        return 0;

    int res = 0;
    vector<vector<int>> height(row + 1, vector<int>(col + 1, 0));
    vector<vector<vector<int>>> dp(row + 1, vector<vector<int>>(col + 1, vector<int>(row + 1, 0)));
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (matrix[i-1][j-1] == '0')
                continue;

            height[i][j] = height[i - 1][j] + 1;
            for (int k = 1; k <= height[i][j]; k++)
            {
                dp[i][j][k] = dp[i][j - 1][k] + k;
                res = max(res, dp[i][j][k]);
            }
        }
    }
    return res;
}




int main()
{
    vector<vector<char>> vec;
    vec.push_back({ '1', '0', '1', '0', '0' });
    vec.push_back({ '1', '0', '1', '1', '1' });
    vec.push_back({ '1', '1', '1', '1', '1' });
    vec.push_back({ '1', '0', '0', '1', '0' });

    int res = maximalRectangle(vec);
    cout << res;
    system("pause");

    return 0;
}









