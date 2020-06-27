

//79. 单词搜索
//给定一个二维网格和一个单词，找出该单词是否存在于网格中。
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，
//其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
//同一个单元格内的字母不允许被重复使用。
//示例 :
//board =
//[
//    ['A', 'B', 'C', 'E'],
//    ['S', 'F', 'C', 'S'],
//    ['A', 'D', 'E', 'E']
//]
//给定 word = "ABCCED", 返回 true
//给定 word = "SEE", 返回 true
//给定 word = "ABCB", 返回 false
//提示：
//board 和 word 中只包含大写和小写英文字母。
//1 <= board.length <= 200
//1 <= board[i].length <= 200
//1 <= word.length <= 10 ^ 3




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


bool backtrack(vector<vector<char>>& board, string word, vector<vector<bool>>&flag, int row, int rownum, int col, int colnum, int pos, int len)
{
    if (row < 0 || row >= rownum || col < 0 || col >= colnum)
        return false;
    if(word[pos] != board[row][col] || flag[row][col] == 1)
        return false;

    if (pos == len - 1)
        return true;

    bool res = false;

    flag[row][col] = 1;
    res = res || backtrack(board, word, flag, row + 1, rownum, col, colnum, pos + 1, len)
        || backtrack(board, word, flag, row - 1, rownum, col, colnum, pos + 1, len)
        || backtrack(board, word, flag, row, rownum, col + 1, colnum, pos + 1, len)
        || backtrack(board, word, flag, row, rownum, col - 1, colnum, pos + 1, len);
    if(res == false)
        flag[row][col] = 0;

    return res;
}


bool exist(vector<vector<char>>& board, string word)
{
    int rownum = board.size();
    int colnum = board[0].size();
    vector<vector<bool>> flag(rownum, vector<bool>(colnum, 0));
    int len = word.size();

    bool res = false;
    for (int i = 0; i < rownum; i++)
    {
        for (int j = 0; j < colnum; j++)
        {
            res = res || backtrack(board, word, flag, i, rownum, j, colnum, 0, len);
        }
    }
    return res;
}


int main()
{
    vector<vector<char>> vec = { { 'A', 'B', 'C', 'E' },{ 'S', 'F', 'C', 'S' },{ 'A', 'D', 'E', 'E' } };
    string str = "SEE"; 
    //string str = "ABCCED"; 
    bool res = exist(vec, str);
    cout << res << endl;
    system("pause");

    return 0;
}

//    ['A', 'B', 'C', 'E'],
//    ['S', 'F', 'C', 'S'],
//    ['A', 'D', 'E', 'E']











