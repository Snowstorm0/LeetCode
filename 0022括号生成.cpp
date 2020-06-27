

//22. 括号生成
//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
//示例：
//输入：n = 3
//输出：
//    "((()))",
//    "(()())",
//    "(())()",
//    "()(())",
//    "()()()"







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


void dfs(vector<string>& res, string str, int leftnum, int rightnum, int n)
{
    if (leftnum < rightnum || leftnum>n || rightnum > n)
        return;
    if (leftnum == rightnum && leftnum == n)
    {
        res.push_back(str);
        return;
    }

    dfs(res, str + '(', leftnum + 1, rightnum, n);
    dfs(res, str + ')', leftnum, rightnum + 1, n);
    return;
}

vector<string> generateParenthesis(int n) 
{
    vector<string> res;
    if (n <= 0)
        return res;
    string str = "";
    int leftnum = 0;
    int rightnum = 0;

    dfs(res, str, leftnum, rightnum, n);

    return res;
}



int main()
{


    vector<string> res = generateParenthesis(3);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    system("pause");

    return 0;

}





