

//62. 不同路径
//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
//机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
//问总共有多少条不同的路径？
//示例 1 :
//输入: m = 3, n = 2
//输出 : 3
//解释 :
//从左上角开始，总共有 3 条路径可以到达右下角。
//1. 向右->向右->向下
//2. 向右->向下->向右
//3. 向下->向右->向右






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


int flag[101][101] = { 0 };
int uniquePaths(int m, int n)
{
    if (m <= 0 || n <= 0)
        return 0;
    if (m == 1 || n == 1)
        return 1;
    if (m == 2 && n == 2)
        return 2;

    int x = m - 1;
    int y = n - 1;
    if (flag[x][y] > 0)
        return flag[x][y];

    flag[x - 1][y] = uniquePaths(m - 1, n);
    flag[x][y - 1] = uniquePaths(m, n - 1);

    flag[x][y] = flag[x - 1][y] + flag[x][y - 1];

    return flag[x][y];
}


int main()
{
    int res = uniquePaths(2, 3);
    cout << res <<  endl;
    system("pause");

    return 0;
}



















