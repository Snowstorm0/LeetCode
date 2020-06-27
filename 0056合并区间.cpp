

//56. 合并区间
//给出一个区间的集合，请合并所有重叠的区间。
//示例 1:
//输入: [[1, 3], [2, 6], [8, 10], [15, 18]]
//输出 : [[1, 6], [8, 10], [15, 18]]
//解释 : 区间[1, 3] 和[2, 6] 重叠, 将它们合并为[1, 6].






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



vector<vector<int>> merge(vector<vector<int>>& nums) 
{
    int len = nums.size();
    if (len <= 0)
        return{};

    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < len; i++)
    {
        int left = i;
        int right = i + 1;
        int end = nums[i][1];
        while (right < len && end >= nums[right][0])
        {
            end = max(end, nums[right][1]);
            right++;
        }
        res.push_back({ nums[i][0], end });
        i = right - 1;

    }
    return res;
}




int main()
{
    vector<vector<int>> vec = { {1,3},{2,6} };
    vector<vector<int>> res = merge(vec);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j<res[i].size(); j++)
            cout << res[i][j];
        cout <<  endl;
    }
    system("pause");

    return 0;
}



















