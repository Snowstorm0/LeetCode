

//49. 字母异位词分组
//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
//示例 :
//输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
//输出 :
//[
//    ["ate", "eat", "tea"],
//    ["nat", "tan"],
//    ["bat"]
//]
//说明：
//    所有输入均为小写字母。
//    不考虑答案输出的顺序。






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



vector<vector<string>> groupAnagrams(vector<string>& str) 
{

    int len = str.size();
    if (len <= 0)
        return{};

    string tmp;
    vector<vector<string>> res;
    vector<string> res1;
    unordered_map<string, int> umap;
    int flag = 0;    //单词所在组的序号

    for (int i = 0; i < len; i++)
    {
        tmp = str[i];
        sort(tmp.begin(), tmp.end());
        if (umap.find(tmp) != umap.end())
        {
            umap[str[i]] = umap.find(tmp)->second;
            res[umap.find(tmp)->second].push_back(str[i]);//将str[i]压入对应序号的组
        }
        else
        {
            umap[tmp] = flag;
            res1.push_back(str[i]);
            res.push_back(res1);
            res1.clear();
            flag++;
        }
    }
    return res;
}

int main()
{
    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    vector<vector<string>> res = groupAnagrams(strs);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << ' ';
        cout << endl;
    }
    system("pause");
    return 0;
}














