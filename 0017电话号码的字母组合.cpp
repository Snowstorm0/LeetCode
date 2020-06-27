

//17. 电话号码的字母组合
//给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//示例:
//输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//说明 : 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。






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






vector<string> letterCombinations(string str)
{
    vector<string> nums = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
    vector<string> res;
    vector<string> tmpres;

    int len = str.size();
    if (len <= 0)
        return res;

    string nullstring = "";

    int flag = str[0] - '0' - 2;
    if (flag < 0 || flag > 7)
        return res;
    for (int j = 0; j < nums[flag].size(); j++)  //res为空时
        res.push_back(nullstring + nums[flag][j]);
    

    for (int i = 1; i < len; i++) //从第二个开始
    {
        int flag = str[i] - '0' - 2;
        if (flag < 0 || flag > 7)
            return res;

        for (int j = 0; j < nums[flag].size(); j++)
        {
            for (int k = 0; k < res.size(); k++)
            {
                tmpres.push_back(res[k] + nums[flag][j]);
            }
        }
        res = tmpres;
        tmpres.clear();
    }
    return res;
}



int main()
{
    string str = "3";
    vector<string> res = letterCombinations(str);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    system("pause");
    return 0;
}



