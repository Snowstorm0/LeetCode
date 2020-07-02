

//152. 乘积最大子数组
//给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组
//（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
//示例 1:
//输入: [2, 3, -2, 4]
//输出 : 6
//解释 : 子数组[2, 3] 有最大乘积 6。
//示例 2 :
//输入 : [-2, 0, -1]
//输出 : 0
//解释 : 结果不能为 2, 因为[-2, -1] 不是子数组。




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


//maxDP[i + 1] = max(maxDP[i] * A[i + 1], A[i + 1], minDP[i] * A[i + 1])
//minDP[i + 1] = min(minDP[i] * A[i + 1], A[i + 1], maxDP[i] * A[i + 1])
//dp[i + 1] = max(dp[i], maxDP[i + 1])


int maxProduct(vector<int>& nums)
{
    int len = nums.size();
    if (len <= 0)
        return 0;
    int maxtmp = nums[0];
    int mintmp = nums[0];
    int res = nums[0];
    for (int i = 1; i < len; i++)
    {
        int tmp = maxtmp;
        maxtmp = max(max(maxtmp * nums[i], mintmp * nums[i]), nums[i]);
        mintmp = min(min(tmp * nums[i], mintmp * nums[i]), nums[i]);
        res = max(res, maxtmp);
    }

    return res;
}


int main()
{
    vector<int> vec = { -4,-3,-2 };
    int res = maxProduct(vec);
    cout << res << endl;
    system("pause");

    return 0;
}



