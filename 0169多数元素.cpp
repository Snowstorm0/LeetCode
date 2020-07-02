

//169. 多数元素
//给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n / 2 ⌋ 的元素。
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。
//示例 1:
//输入: [3, 2, 3]
//输出 : 3
//示例 2 :
//输入 : [2, 2, 1, 1, 1, 2, 2]
//输出 : 2




#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack> 
#include <map> 
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;



int majorityElement(vector<int>& nums)
{
    unordered_map<int,int> umap;
    int len = nums.size();
    for (int i : nums)
    {
        umap[i]++;
        if (umap[i] > len / 2)
            return i;
    }
    return 0;
}



int main()
{
    vector<int> vec = { 1,2,1 };
    int res = majorityElement(vec);

    cout << res << endl;
    system("pause");

    return 0;
}











