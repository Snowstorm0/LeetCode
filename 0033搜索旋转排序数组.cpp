

//33. 搜索旋转排序数组
//假设按照升序排序的数组在预先未知的某个点上进行了旋转。
//(例如，数组[0, 1, 2, 4, 5, 6, 7] 可能变为[4, 5, 6, 7, 0, 1, 2])。
//搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 - 1 。
//你可以假设数组中不存在重复的元素。
//你的算法时间复杂度必须是 O(log n) 级别。
//示例 1:
//输入: nums = [4, 5, 6, 7, 0, 1, 2], target = 0
//输出 : 4






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



int search(vector<int>& nums, int target) 
{
    int len = nums.size();
    if (len <= 0)
        return -1;

    int left = 0;
    int right = len - 1;
    while (left <= right)
    {
        int mid = (left + right) >> 1;

        if (nums[mid] == target)
            return mid;

        if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        else
        {
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }

    }
    return -1;
}

int main()
{
    vector<int> vec = { 4, 5, 6, 7, 0, 1, 2 };
    int res = search(vec, 0);

    cout << res << endl;
    system("pause");

    return 0;

}




