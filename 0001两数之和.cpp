
//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 
//两个 整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。


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


vector<int> twoSum(vector<int>& nums, int target) 
{
    vector<int> res;
    int len = nums.size();
    if (len <= 0)
        return res;

    unordered_map<int, int> tmp;

    for (int i = 0; i < len; i++)
    {
        if (tmp.find(target - nums[i]) != tmp.end())
        {
            res.push_back(tmp[target - nums[i]]);
            res.push_back(i);
            return res;
            //  m[target-nums[i]]为已经加入map的元素的索引，所以小于本轮循环中的i，放在前面

        }
        tmp[nums[i]] = i;
    }

    return res;


}





int main()
{
    vector<int>nums = { 0,4,3,0 };
    int target = 0;
    vector<int> res = twoSum(nums, target);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    system("pause");

}

