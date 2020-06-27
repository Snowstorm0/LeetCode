

//3. 无重复字符的最长子串
//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//示例 1 :
//输入: "abcabcbb"
//输出 : 3
//解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。



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

int lengthOfLongestSubstring(string s)
{
    int len = s.size();
    if (len <= 0)
        return 0;

    unordered_map<char, int> hash;

    int sta = 0;
    int end = 0;
    int len1 = 0;
    int res = 0;

    for (int i = 0; i < len; i++)
    {
        char tmp = s[end];

        //仅当s[start,end) 中存在s[end]时更新start
        if (hash.find(tmp) != hash.end() && hash[tmp] >= sta)
        {
            sta = hash[tmp] + 1;
        }

        hash[tmp] = end;
        end++;
        len1 = end - sta;

        res = max(res, len1);
    }

    return res;
}


int main()
{

    string s = "abcabcbb";
    int res = lengthOfLongestSubstring(s);
    cout << res << endl;
    system("pause");

    return 0;
}









