//
// Created by loki on 2022/4/24.
//

#include "../common.h"

/*
 * 从低位开始遍历，用last记录上一个1的位置，如果在i位找到了1，那么就i-last更新答案，每次循环后n = n >> 1右移一位
 * i表示的是位数
 */
class Solution {
public:
    int binaryGap(int n) {
        int last = -1, ans = 0;
        for (int i = 0; n; ++i) { // 这里循环终止条件是n大于0
            if (n & 1) {
                if (last != -1) {
                    ans = max(ans, i - last);
                }
                last = i;
            }
            n >>= 1;
        }
        return ans;
    }
};