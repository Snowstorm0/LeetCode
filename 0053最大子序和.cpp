

//53. 最大子序和
//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//示例 :
//输入: [-2, 1, -3, 4, -1, 2, 1, -5, 4],
//输出 : 6
//解释 : 连续子数组[4, -1, 2, 1] 的和最大，为 6。
//进阶 :
//如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。






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


int findMaxCrossingSubarray(vector<int>& nums, int left, int right, int mid)
{
    if (left == right)
        return nums[left];

    int leftsum = 0;
    int leftmax = INT_MIN;
    for (int i = mid; i >= left; i--)
    {
        leftsum = leftsum + nums[i];
        leftmax = max(leftmax, leftsum);
    }

    int rightsum = 0;
    int rightmax = INT_MIN;
    for (int i = mid + 1; i <= right; i++)
    {
        rightsum = rightsum + nums[i];
        rightmax = max(rightmax, rightsum);
    }

    return(leftmax + rightmax);

}


int maxSubArrayHelper(vector<int>& nums, int left, int right)
{
    if (left == right)
        return nums[left];

    int mid = (left + right) >> 1;
    int leftsum = maxSubArrayHelper(nums, left, mid);
    int rightsum = maxSubArrayHelper(nums, mid + 1, right);
    int midsum = findMaxCrossingSubarray(nums, left, right, mid);

    return max(max(leftsum, rightsum), midsum);
}



int maxSubArray(vector<int>& nums) 
{
    int len = nums.size();
    if (len <= 0)
        return 0;

    int res = maxSubArrayHelper(nums, 0, len - 1);

    return res;
}



int main()
{
    vector<int> vec = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int res = maxSubArray(vec);
    cout << res << endl;
    system("pause");

    return 0;
}














