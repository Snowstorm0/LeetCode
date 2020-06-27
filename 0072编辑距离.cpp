

//72. 编辑距离
//给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
//你可以对一个单词进行如下三种操作：
//插入一个字符
//删除一个字符
//替换一个字符
//示例 1：
//输入：word1 = "horse", word2 = "ros"
//输出：3
//解释：
//horse->rorse(将 'h' 替换为 'r')
//rorse->rose(删除 'r')
//rose->ros(删除 'e')




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


int minDistance(string word1, string word2)
{
    int len1 = word1.size();
    int len2 = word2.size();
    if (len1 < 0 || len2 < 0)
        return 0;

    vector<vector<int> > sum(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 0; i <= len1; i++)
        sum[i][0] = i;
    for (int i = 0; i <= len2; i++)
        sum[0][i] = i;

    for(int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
        {
            sum[i][j] = min(sum[i - 1][j - 1], min(sum[i - 1][j], sum[i][j - 1])) + 1;

            if (word1[i - 1] == word2[j - 1])
                sum[i][j] = sum[i - 1][j - 1];
        }

    return sum[len1][len2];
}



int main()
{
    string str1 = "horse";
    string str2 = "ros";
    int res = minDistance(str1, str2);
    cout << res <<  endl;
    system("pause");

    return 0;
}












