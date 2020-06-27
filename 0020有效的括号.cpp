

//20. 有效的括号
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。
//示例 1:
//输入: "()"
//    输出 : true






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


bool match(char a, char b)
{
    if (a == '(' && b == ')' || a == '{' && b == '}' || a == '[' && b == ']')
        return true;
    else
        return false;
}

bool isValid(string s) 
{
    int len = s.size();
    if (len == 0)
        return true;

    stack<char> sta;
    for (int i = 0; i < len; i++)
    {
        if (sta.empty())
            sta.push(s[i]);
        else if (match(sta.top(), s[i]))
            sta.pop();
        else
            sta.push(s[i]);
    }

    if (sta.empty())
        return true;
    else
        return false;
}


int main()
{
    string str = "([)";

    bool res = isValid(str);
    cout << res << endl;
    system("pause");

    return 0;
}

