//
// Created by loki on 2022/4/5.
//

#include "../common.h"

unordered_set<int> prime = {2,3,5,7,11,13,17,19,23,29,31}; // 32位，所以32内的质数打表
int countPrimeSetBits(int left, int right) {
    int ans = 0;
    for(int i = left; i <= right; i++) {
        int cnt = __builtin_popcount (i); // 内置函数，二进制1的个数
        if(prime.count(cnt)) ans++;
    }
    return ans;
}