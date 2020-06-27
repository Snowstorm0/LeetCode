

//34. 在排序数组中查找元素的第一个和最后一个位置
//给定一个按照升序排列的整数数组 nums，和一个目标值 target。
//找出给定目标值在数组中的开始位置和结束位置。
//你的算法时间复杂度必须是 O(log n) 级别。
//如果数组中不存在目标值，返回[-1, -1]。
//示例 1:
//输入: nums = [5, 7, 7, 8, 8, 10], target = 8
//输出 : [3, 4]






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



vector<int> searchRange(vector<int>& nums, int target) 
{
    vector<int> res = { -1, -1 };

    int len = nums.size();
    if (len <= 0 || target < nums[0] || target > nums[len - 1])
        return res;

    int left = 0;
    int right = len - 1;
    int mid1 = -1, mid2 = -1;
    while (left <= right)
    {
        mid1 = (left + right) >> 1;
        if (target <= nums[mid1])
            right = mid1 - 1;
        else 
            left = mid1 + 1;
    }
    if (right + 1 == 0)  //开头就是target
        res[0] = 0;
    else if (nums[right] != target && nums[right + 1] == target)
        res[0] = right + 1;
    else
        return{ -1,-1 };

    left = 0;
    right = len - 1;
    while (left <= right)
    {
        mid2 = (left + right) >> 1;
        if (target >= nums[mid2])
            left = mid2 + 1;
        else 
            right = mid2 - 1;
    }
    if (left - 1 == len - 1)  //末尾是target
        res[1] = left - 1;
    else if (nums[left] != target && nums[left - 1] == target)
        res[1] = left - 1;
    else
        return{ -1,-1 };

    return res;
}




int main()
{
    vector<int> vec = { 1 };
    vector<int> res = searchRange(vec, 1);

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    system("pause");

    return 0;

}

