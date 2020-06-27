

//11. 盛最多水的容器
//给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点(i, ai) 。
//在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为(i, ai) 和(i, 0)。
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//说明：你不能倾斜容器，且 n 的值至少为 2。
//图中垂直线代表输入数组[1, 8, 6, 2, 5, 4, 8, 3, 7]。
//在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
//示例：
//输入：[1, 8, 6, 2, 5, 4, 8, 3, 7]
//输出：49






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


int maxArea(vector<int>& height)
{
    int len = height.size();
    if (len <= 1)
        return 0;

    int left = 0;
    int right = len - 1;
    int res = 0;
    int tmp = 0;

    while (left < right)
    {
        tmp = (right - left)*min(height[left], height[right]);
        res = max(res, tmp);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return res;
}



int main()
{
    vector<int> vec = { 2,3,4,5,18,17,6 };
    int restlt = maxArea(vec);
    printf("result: %d\n", restlt);
    system("pause");
    return 0;
}














