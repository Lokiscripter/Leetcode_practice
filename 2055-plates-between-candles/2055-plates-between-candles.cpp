//
// Created by loki on 2022/3/8.
//

#include "../common.h"

/*
 * 核心问题一：查找区间[i,j]内最左边和最右边的蜡烛的下标[l,r]
 * 核心问题二：求出区间[l,r]中的盘子
 * 问题一解决：
 *      区间映射，对于字符串s，求出每个字符离它左边和右边最近的蜡烛的位置，分别用数组保存
 * 问题二解决：
 *      前缀和解决，使用数组preSum存储蜡烛数量的前缀和，对于任意的下标i，preSum[i]表示s[0]~s[i]之间的盘子的数量
 *      对于任意区间[l,r]内的盘子数量有preSum[r]-preSum[l]
 */
vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    int n = s.size();
    vector<int> left(n);
    vector<int> right(n);
    vector<int> preSum(n);
    vector<int> ans;
    int sum = 0;
    // 计算前缀和
    for(int i = 0; i < n; i ++) {
        if(s[i] == '*') {
            sum ++;
        }
        preSum[i] = sum;
    }
    int cur = -1;
    // 记录左边蜡烛的位置
    for(int i = 0; i < n; i ++) {
        if(s[i] == '|') {
            cur = i;
        }
        left[i] = cur;
    }
    cur = n;
    // 记录右边蜡烛的位置
    for(int i = n - 1; i >= 0; i --) {
        if(s[i] == '|') {
            cur = i;
        }
        right[i] = cur;
    }
    for(auto& q : queries) {
        int l = right[q[0]], r = left[q[1]];
        int count = (l < n && r > -1 && l < r) ? preSum[r] - preSum[l] : 0;
        ans.push_back(count);
    }
    return ans;
}