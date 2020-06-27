

//78. 子集
//给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
//说明：解集不能包含重复的子集。
//示例 :
//输入: nums = [1, 2, 3]
//输出 :
//[
//    [3],
//    [1],
//    [2],
//    [1, 2, 3],
//    [1, 3],
//    [2, 3],
//    [1, 2],
//    []
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



void backtrack(vector<int>& nums, int sta, vector<int>& tmp, vector<vector<int>>& res)
{
    res.push_back(tmp);
    int len = nums.size();

    for (int i = sta; i < len; i++)
    {
        tmp.push_back(nums[i]);
        backtrack(nums, i+1, tmp, res);
        tmp.pop_back();
    }

    return;
}



vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>>res;
    int len = nums.size();
    if (len <= 0)
        return res;

    vector<int> tmp;
    backtrack(nums, 0, tmp, res);
    return res;

}




int main()
{
    vector<int> vec = { 1, 2, 3 };
    vector<vector<int>> res = subsets(vec);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j];
        cout << endl;

    }
    system("pause");

    return 0;
}













