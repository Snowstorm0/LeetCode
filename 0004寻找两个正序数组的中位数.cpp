

//4. 寻找两个正序数组的中位数
//给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
//请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
//你可以假设 nums1 和 nums2 不会同时为空。
//示例 1:
//nums1 = [1, 3]，nums2 = [2]，则中位数是 2.0



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

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    if (n > m)  //保证数组1一定最短
    {
        return findMedianSortedArrays(nums2, nums1);
    }

    // Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
    int LMax1, LMax2, RMin1, RMin2, c1, c2, lo = 0, hi = 2 * n;  
    //lo：low；hi：high；虚拟加了'#'所以数组1长度是2n+1，下标为2n，二分法是二分下标
    
    while (lo <= hi)   //二分
    {
        c1 = (lo + hi) / 2;  //c1是二分的结果
        c2 = m + n - c1;

        LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
        RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
        LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
        RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];

        if (LMax1 > RMin2)
            hi = c1 - 1;
        else if (LMax2 > RMin1)
            lo = c1 + 1;
        else
            break;
    }
    return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
}


int main()
{

    vector<int> nums1 = { 1,3 };
    vector<int> nums2 = { 2 };

    double res = findMedianSortedArrays(nums1, nums2);
    cout << res << endl;
    system("pause");

    return 0;
}

