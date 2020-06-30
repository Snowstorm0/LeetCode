

//136. 只出现一次的数字
//给定一个非空整数数组，除了某个元素只出现一次以外，
//其余每个元素均出现两次。找出那个只出现了一次的元素。
//说明：
//你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
//示例 1:
//输入: [2, 2, 1]
//输出 : 1




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



int singleNumber(vector<int>& nums)
{
    int res = 0;
    for (int i : nums)
        res = res^i;
    return res;
}



int main()
{
    vector<int> vec = { 2, 2, 1 };
    int res = singleNumber(vec);
    cout << res << endl;
    system("pause");

    return 0;
}







