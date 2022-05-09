//
// Created by loki on 2022/5/9.
//

#include "../common.h"

/*
 * 记录当前可用的最小值min和做大值max，比如0-4就是min是0，max是4
 * 当s[i] = 'I'的时候，就把当前的最小值放进result，然后min++
 * 当s[i] = 'D'的时候，就把当前的最大值放进result，然后max--
 * 利用了贪心的思想
 */
vector<int> diStringMatch(string s) {
    vector<int> result;
    int min = 0, max = s.size();
    for(auto& str:s) {
        /* 遇到‘I’找到剩余数中的最小值放入resul中 */
        if(str == 'I') result.emplace_back(min++);
            /* 遇到‘D’找到剩余数中的最大值放入resul中 */
        else result.emplace_back(max--);
    }
    result.emplace_back(max);
    return result;
}