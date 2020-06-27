

//46. 全排列
//给定一个 没有重复 数字的序列，返回其所有可能的全排列。
//示例 :
//输入: [1, 2, 3]
//输出 :
//[
//    [1, 2, 3],
//    [1, 3, 2],
//    [2, 1, 3],
//    [2, 3, 1],
//    [3, 1, 2],
//    [3, 2, 1]
//]






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


void func(vector<int>& nums, vector<bool>& flag, vector<int>& res1, vector<vector<int>>& res)
{
    int len = nums.size();
    int len1 = res1.size();
    if (len == len1)
    {
        res.push_back(res1);
        return;
    }

    for (int i = 0; i < len; i++)
    {
        if (flag[i] == 0)
        {
            res1.push_back(nums[i]);
            flag[i] = 1;
            func(nums, flag, res1, res);
            res1.pop_back();
            flag[i] = 0;
        }
    }
    return;
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> res;
    int len = nums.size();
    if (len <= 0)
        return res;

    vector<bool> flag(len, 0);
    vector<int> res1;
    func(nums, flag, res1, res);
    return res;

}

int main()
{
    vector<int> vec = { 1, 2, 3 };
    vector<vector<int>> res = permute(vec);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
            cout << res[i][j];
        cout << endl;
    }
    system("pause");
    return 0;
}














