

//15. 三数之和
//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
//使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
//注意：答案中不可以包含重复的三元组。
//示例：
//给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//满足要求的三元组集合为：
//[
//    [-1, 0, 1],
//    [-1, -1, 2]
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



vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> res;
    int len = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < len - 2 && nums[i] <= 0; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])  //第一个数应该取一串相同数字的第一个
            continue;
        int left = i + 1;
        int right = len - 1;

        while (left < right && nums[right] >= 0)
        {
            if (nums[i] + nums[left] + nums[right] == 0)
            {
                res.push_back({ nums[i], nums[left], nums[right] });

                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (nums[i] + nums[left] + nums[right] < 0)
                left++;
            else
                right--;
        }
    }
    return res;
}




int main()
{
    vector<int> vec = { 0,0,0,0 };
    vector<vector<int>> res = threeSum(vec);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j<res[i].size(); j++)
            cout << res[i][j] << ' ';
        cout << endl;
    }
    system("pause");

    return 0;
}













