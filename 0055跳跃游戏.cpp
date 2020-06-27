

//55. 跳跃游戏
//给定一个非负整数数组，你最初位于数组的第一个位置。
//数组中的每个元素代表你在该位置可以跳跃的最大长度。
//判断你是否能够到达最后一个位置。
//示例 1:
//输入: [2, 3, 1, 1, 4]
//输出 : true
//解释 : 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。






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


bool canJump(vector<int>& nums)
{
    int len = nums.size();

    int maxjump = 0;
    for (int i = 0; i < len; i++)
    {
        if (maxjump < i)
            return false;
        maxjump = max(maxjump, nums[i] + i);
    }

    return true;
}




int main()
{
    vector<int> vec = { 2, 3, 1, 1, 4 };
    bool res = canJump(vec);
    cout << res << endl;
    system("pause");

    return 0;
}





















