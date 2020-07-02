

//198. 打家劫舍
//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
//影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
//如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
//给定一个代表每个房屋存放金额的非负整数数组，
//计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
//示例 1：
//输入：[1, 2, 3, 1]
//输出：4
//解释：偷窃 1 号房屋(金额 = 1) ，然后偷窃 3 号房屋(金额 = 3)。
//偷窃到的最高金额 = 1 + 3 = 4 。




#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack> 
#include <map> 
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//空间优化
//int rob(vector<int>& nums) 
//{
//    int prev = 0;
//    int curr = 0;
//
//    for (int i : nums) 
//    {
//        int temp = max(curr, prev + i);
//        prev = curr;
//        curr = temp;
//    }
//
//    return curr;
//}

int rob(vector<int>& nums)
{
    int len = nums.size();
    if (len <= 0)
        return 0;
    if (len == 1)
        return nums[0];

    vector<int> dp(len + 1, 0);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i <= len; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    return dp[len];
}


int main()
{
    vector<int> vec = { 2, 1 };
    int res = rob(vec);

    cout << res << endl;
    system("pause");

    return 0;
}










