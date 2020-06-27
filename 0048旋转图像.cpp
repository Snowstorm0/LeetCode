

//48. 旋转图像
//给定一个 n × n 的二维矩阵表示一个图像。
//将图像顺时针旋转 90 度。
//说明：
//你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
//示例 1:
//给定 matrix =
//[
//    [1, 2, 3],
//    [4, 5, 6],
//    [7, 8, 9]
//],
//原地旋转输入矩阵，使其变为:
//[
//    [7, 4, 1],
//    [8, 5, 2],
//    [9, 6, 3]
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


void rotate(vector<vector<int>>& matrix) 
{
    int len = matrix.size();

    for (int i = 0; i < len; i++)
        for (int j = i; j < len; j++)
            swap(matrix[i][j], matrix[j][i]);
        
    int midlen = len >> 1;
    for (int i = 0; i < len; i++)
        for (int j = 0; j < midlen; j++)
            swap(matrix[i][j], matrix[i][len - j - 1]);
    return;
}



int main()
{
    vector<vector<int>> res = { { 1, 2, 3 }, { 4, 5, 6 },{ 7, 8, 9 } };
    rotate(res);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
            cout << res[i][j];
        cout << endl;
    }
    system("pause");
    return 0;
}














