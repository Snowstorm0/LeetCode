

//42. 接雨水
//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//上面是由数组[0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1] 表示的高度图，
//在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。
//示例 :
//输入: [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
//输出 : 6






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


int trap(vector<int>& height) 
{
    int len = height.size();

    if (len <= 0)
        return 0;

    stack<int> sta;
    int res = 0;
    for (int i = 0; i < len; i++)
    {
        while (!sta.empty() && height[sta.top()] < height[i])
        {
            int tmp = height[sta.top()];
            sta.pop();
            if (sta.empty())
                break;

            int left = sta.top();
            int right = i;
            int w = right - left - 1;
            int h = min(height[left], height[right]) - tmp;

            res = res + w*h;
        }
        sta.push(i);
    }
    return res;
}



int main()
{
    vector<int> vec = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    int res = trap(vec);

    cout << res << endl;
    system("pause");
    return 0;
}














