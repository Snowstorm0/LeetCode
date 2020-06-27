

//76. 最小覆盖子串
//给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。
//示例：
//输入 : S = "ADOBECODEBANC", T = "ABC"
//输出 : "BANC"
//说明：
//如果 S 中不存这样的子串，则返回空字符串 ""。
//如果 S 中存在这样的子串，我们保证它是唯一的答案。




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




string minWindow(string s, string t)
{
    int len1 = s.size();
    int len2 = t.size();

    unordered_map<char, int> scount;
    unordered_map<char, int> tcount;
    int count = 0;
    int left = 0;
    int right = 0;
    string res;
    int reslen = INT_MAX;

    for (int i = 0; i < len2; i++)
        tcount[t[i]]++;

    while (right < len1)  //right左移
    {
        char righttmp = s[right];
        scount[righttmp]++;
        if (tcount.count(righttmp) && scount[righttmp] <= tcount[righttmp])
            count++;

        while (left<=right && count == len2)  //left右移
        {
            if (reslen > (right - left + 1) )
            {
                reslen = (right - left + 1);
                res = s.substr(left, reslen);
            }

            char lefttmp = s[left];
            if (tcount.count(lefttmp) && scount[lefttmp] <= tcount[lefttmp])
                count--;

            scount[lefttmp]--;
            left++;
        }
        right++;
    }
    return res;

}


int main()
{
    string str1 = "ADOBECODEBANC";
    string str2 = "ABC";
    string res = minWindow(str1, str2);
    cout << res;
    system("pause");

    return 0;
}

















