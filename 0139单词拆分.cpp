

//139. 单词拆分
//给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，
//判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
//说明：
//拆分时可以重复使用字典中的单词。
//你可以假设字典中没有重复的单词。
//示例 1：
//输入 : s = "leetcode", wordDict = ["leet", "code"]
//输出 : true
//解释 : 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。




#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack> 
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;




bool wordBreak(string s, vector<string>& wordDict)
{
    int len = s.size();
    vector<bool> flag(len + 1, 0);
    flag[0] = 1;
    for (int i = 0; i < len; i++)
    {
        if (flag[i] == 0)
            continue;
        string tmp = s.substr(i);
        for (string word : wordDict)
            if (tmp.find(word) == 0)
            {
                int tmplen = word.size();
                flag[i + tmplen] = 1;
            }
    }
    return flag[len];
}






int main()
{
    string str = "abc";
    vector<string> vec = { "ab", "c" };
    int res = wordBreak(str, vec);
    cout << res << endl;
    system("pause");

    return 0;
}







