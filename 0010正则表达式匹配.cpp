

//10. 正则表达式匹配
//给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
//'.' 匹配任意单个字符
//'*' 匹配零个或多个前面的那一个元素
//所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
//说明 :
//s 可能为空，且只包含从 a - z 的小写字母。
//p 可能为空，且只包含从 a - z 的小写字母，以及字符.和 *。
//示例 1 :
//    输入 :
//    s = "aa"
//    p = "a"
//    输出 : false
//    解释 : "a" 无法匹配 "aa" 整个字符串。


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


bool match(char* str, char* pattern)
{
    if (str == nullptr || pattern == nullptr)
        return false;

    if (*str == '\0' && *pattern == '\0') // 结束
        return true;
    else if (*str != '\0' && *pattern == '\0')
        return false;
    else if (*str == '\0' && *pattern != '\0')
    {
        if (*(pattern + 1) == '*')
            return match(str, pattern + 2);
        else
            return false;
    }

    else if (*(pattern + 1) != '*') // 无*
    {
        if (*str == *pattern || *pattern == '.')
            return match(str + 1, pattern + 1);
        else
            return false;
    }
    else if (*(pattern + 1) == '*') // 有 *
    {
        if (*str == *pattern || *pattern == '.')
            return (match(str, pattern + 2) || match(str + 1, pattern) || match(str + 1, pattern + 2));
        else if (*str != *pattern)
            return match(str, pattern + 2);
    }
    return false;
}




bool isMatch(string s, string p)
{
    char* str = &s[0];
    char* pattern = &p[0];
    return match(str, pattern);
}


int main()
{
    const int len = 100;
    char str[len] = "bbbba", pattern[len] = ".*a*a";
    bool restlt = match(str, pattern);
    printf("result: %d\n", restlt);
    system("pause");
    return 0;
}









