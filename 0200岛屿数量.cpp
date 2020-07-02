

//200. 岛屿数量
//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
//岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
//此外，你可以假设该网格的四条边均被水包围。
//示例 1:
//输入:
//11110
//11010
//11000
//00000
//输出 : 1




#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack> 
#include <map> 
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;




void dfs(vector<vector<char>>& grid, int row, int col)
{
    if (row<0 || row>=grid.size() || col<0 || col>=grid[0].size())
        return;
    if(grid[row][col] == '0')
        return;

    grid[row][col] = '0';
    dfs(grid, row + 1, col);
    dfs(grid, row - 1, col);
    dfs(grid, row, col + 1);
    dfs(grid, row, col - 1);
    return;
}
int numIslands(vector<vector<char>>& grid)
{
    int len = grid.size();
    if (len <= 0)
        return 0;
    int len1 = grid[0].size();
    if (len1 <= 0)
        return 0;

    int res = 0;
    for(int i=0;i<len;i++)
        for (int j = 0; j < len1; j++)
        {
            if (grid[i][j] == '1')
            {
                res++;
                dfs(grid, i, j);
            }
        }
    return res;
}



int main()
{
    vector<char> vec1 = { '1', '1', '1', '1', '0' };
    vector<char> vec2 = { '1', '1', '0', '1', '0' };
    vector<char> vec3 = { '1', '1', '0', '0', '0' };
    vector<vector<char>> mat = { vec1, vec2,vec3 };
    int res = numIslands(mat);

    cout << res << endl;
    system("pause");

    return 0;
}





