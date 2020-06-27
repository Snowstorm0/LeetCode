

//5. 最长回文子串
//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
//示例 :
//输入 : "babad"
//输出 : "bab"
//注意 : "aba" 也是一个有效答案。



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

//中心扩展法

int expendaroundcenter(string s, int left, int right)
{
    int len = s.size();
    if (len <= 1)
        return len;

    int len1 = 0;
    while (left >= 0 && right < len)
    {
        if (s[left] == s[right])
        {
            len1 = right - left + 1;

            left--;
            right++;
        }
        else
            break;
    }
    return len1;
}

string longestPalindrome(string s) 
{
    int len = s.size();
    if (len <= 1)
        return s;

    int res = 0;
    int tmplen = 0;
    int sta = 0;
    int end = 0;
    for (int i = 0; i < len; i++)
    {
        int len1 = expendaroundcenter(s, i, i); //一个元素为中心
        int len2 = expendaroundcenter(s, i, i+1); //两个元素为中心
        tmplen = max(len1, len2);
        if (tmplen > res)
        {
            res = tmplen;
            sta = i - (tmplen - 1) / 2;
            end = i + tmplen / 2;
        }
    }

    return s.substr(sta, res);

}



int main()
{
    string str = "babad";
    string res = longestPalindrome(str);
    cout << res << endl;
    system("pause");

    return 0;
}




