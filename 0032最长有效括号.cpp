

//32. 最长有效括号
//给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
//示例 1:
//输入: "(()"
//    输出 : 2
//    解释 : 最长有效括号子串为 "()"
//输入: ")()())"
//    输出 : 4
//    解释 : 最长有效括号子串为 "()()"






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




//https://leetcode-cn.com/problems/longest-valid-parentheses/solution/dong-tai-gui-hua-si-lu-xiang-jie-c-by-zhanganan042/
int longestValidParentheses(string s) 
{
    int len = s.size();
    if (len <= 0)
        return 0;

    vector<int> vec(len, 0);
    int res = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == ')')
        {
            if ((i - 1) >= 0 && s[i - 1] == '(')
            {
                if (i - 2 >= 0)
                    vec[i] = vec[i - 2] + 2;
                else
                    vec[i] = 2;
            }

            else if ((i - 1) >= 0)
            {
                if (i - vec[i - 1] - 2 >= 0 && s[i - vec[i - 1] - 1] == '(')
                    vec[i] = 2 + vec[i - 1] + vec[i - vec[i - 1] - 2];
                else if (i - vec[i - 1] - 1 >= 0 && s[i - vec[i - 1] - 1] == '(')
                    vec[i] = 2 + vec[i - 1];
            }
        }
        res = max(res, vec[i]);
    }

    //for (int i = 0; i < len; i++)
    //    cout << vec[i] << endl;
    //system("pause");
    return res;
}

int main()
{
    string str = "(()())";
    int res = longestValidParentheses(str);

    cout << res << endl;
    system("pause");

    return 0;

}

