

//31. 下一个排列
//实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
//如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
//必须原地修改，只允许使用额外常数空间。
//以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
//1, 2, 3 → 1, 3, 2
//3, 2, 1 → 1, 2, 3
//1, 1, 5 → 1, 5, 1







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




//从最末位寻找第一个破坏升序的数nums[pos - 1], 然后在遍历过的数里寻找比该数大的最小的一个数。
//如遍历过的数为[7, 6, 4, 3], nums[pos - 1]为5, 则5需要与6进行交换, 在将[7, 5, 4, 3]改为升序(这里使用reverse)。
//
//遍历过的数从后往前一定是升序, 故改为从前往后升序只需要反转该部分即可。
//寻找第一个比nums[pos - 1]大的数, 只需改为从前往后升序之后, 从升序的第一个数开始遍历比较大小即可。

void nextPermutation(vector<int>& nums)
{
    int len = nums.size();
    if (len <= 1)
        return;

    int flag = len - 1;

    while (flag > 0 && nums[flag] <= nums[flag - 1])
        flag--;

    reverse(nums.begin() + flag, nums.end());

    if (flag == 0) //已经最大
        return;

    for (int i = flag; i < len; i++)
    {
        if (nums[i] > nums[flag-1])
        {
            swap(nums[i], nums[flag-1]);
            break;
        }
    }

    return;
}



int main()
{
    vector<int> vec = { 3, 5, 4, 3, 2, 1 }; //4 1 2 3 3 5

    nextPermutation(vec);

    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << endl;
    system("pause");

    return 0;

}




