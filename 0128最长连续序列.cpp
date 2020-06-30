

//128. 最长连续序列
//给定一个未排序的整数数组，找出最长连续序列的长度。
//要求算法的时间复杂度为 O(n)。
//示例 :
//输入: [100, 4, 200, 1, 3, 2]
//输出 : 4
//解释 : 最长连续序列是[1, 2, 3, 4]。它的长度为 4。




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



int longestConsecutive(vector<int>& nums)
{
    int len = nums.size();
    if (len <= 0)
        return 0;
    unordered_map<int, int> umap;
    int res = 0;
    int tmp = 0;
    for (int i : nums)
        umap[i] = i;

    for (int i : nums)
    {
        int flag = i;
        if (umap.find(flag - 1) == umap.end()) //找到起始位置才开始计数
        {
            tmp = 0;
            while (umap.find(flag + tmp) != umap.end())
                tmp++;
            res = max(res, tmp);
        }
    }
     
    return res;
}


int main()
{
    vector<int> vec = { 100, 4, 200, 1, 3, 2 };
    int res = longestConsecutive(vec);
    cout << res << endl;
    system("pause");

    return 0;
}







