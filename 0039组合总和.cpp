

//39. 组合总和
//给定一个无重复元素的数组 candidates 和一个目标数 target ，
//找出 candidates 中所有可以使数字和为 target 的组合。
//candidates 中的数字可以无限制重复被选取。
//说明：
//所有数字（包括 target）都是正整数。
//解集不能包含重复的组合。
//示例 1:
//输入: candidates = [2, 3, 6, 7], target = 7,
//所求解集为 :
//[
//    [7],
//    [2, 2, 3]
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



void DFS(vector<int>& candidates, int target, int sta, int len, vector<vector<int>>& res, vector<int>& res1)
{
    if (target == 0)
    {
        res.push_back(res1);
        return;
    }

    for (int i = sta; i < len; i++)
    {
        if (candidates[i] <= target)
        {
            res1.push_back(candidates[i]);
            DFS(candidates, target - candidates[i], i, len, res, res1);
            res1.pop_back();
        }
    }
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
    vector<vector<int>> res;
    vector<int> res1;
    int len = candidates.size();
    if (len <= 0)
        return res;

    DFS(candidates, target, 0, len, res, res1);
    return res;
}


int main()
{
    vector<int> vec = { 8, 7, 4, 3 };
    vector<vector<int>> res = combinationSum(vec, 11);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j];
        cout <<  endl;
    }
    system("pause");
    return 0;
}














