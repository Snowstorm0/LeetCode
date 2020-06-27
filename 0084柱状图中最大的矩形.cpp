

//84. 柱状图中最大的矩形
//给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
//求在该柱状图中，能够勾勒出来的矩形的最大面积。
//以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为[2, 1, 5, 6, 2, 3]。
//图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
//示例 :
//输入: [2, 1, 5, 6, 2, 3]
//输出 : 10




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


int largestRectangleArea(vector<int>& heights)
{
    heights.push_back(0);  //后插0，最后迫使所有元素出栈
    heights.insert(heights.begin(), 0);//前插0，防止栈空
    int len = heights.size();
    if (len <= 0)
        return 0;

    stack<int> sta;
    int res = 0;
    for (int i = 0; i < len; i++)
    {
        while (!sta.empty() && heights[sta.top()] > heights[i])
        {
            int cur = sta.top();
            sta.pop();
            int left = sta.top() + 1;  // heights[sta.top()] 是左边第一个比cur小的
            int right = i - 1;  // heights[i] 是右边第一个比cur小的
            int w = right - left + 1;  
            int h = heights[cur];
            res = max(res, w*h);
        }
        sta.push(i);
    }
    return res;
}

int main()
{
    //vector<int> vec = { 2, 1, 5, 6, 2, 3 };
    vector<int> vec = { 2, 1,2 };
    int res = largestRectangleArea(vec);
    cout << res << endl;
    system("pause");

    return 0;
}













