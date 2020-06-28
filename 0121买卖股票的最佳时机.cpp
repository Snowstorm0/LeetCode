

//121. 买卖股票的最佳时机
//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
//注意：你不能在买入股票前卖出股票。
//示例 1:
//输入: [7, 1, 5, 3, 6, 4]
//输出 : 5
//解释 : 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，
//最大利润 = 6 - 1 = 5 。
//注意利润不能是 7 - 1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。




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




int maxProfit(vector<int>& prices)
{
    int len = prices.size();
    if (len <= 0)
        return 0;

    vector<int> vec;
    prices.push_back(-1);
    int res = 0;
    for (int i = 0; i <= len; i++)
    {
        while (!vec.empty() && vec.back() > prices[i])
        {
            res = max(vec.back() - vec.front(), res);
            vec.pop_back();
        }
        vec.push_back(prices[i]);
    }
    return res;
}





int main()
{
    vector<int> vec = { 7, 1, 5, 3, 6, 4 };
    int res = maxProfit(vec);
    cout << res << endl;
    system("pause");

    return 0;
}







