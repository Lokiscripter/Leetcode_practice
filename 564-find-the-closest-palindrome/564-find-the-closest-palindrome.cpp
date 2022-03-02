//
// Created by loki on 2022/3/2.
//

#include "../common.h"

// https://leetcode-cn.com/problems/find-the-closest-palindrome/
/*
对于任意一个数，如12345，其最近的回文数只会从以下五种中得到：

将前一半填入后一半：12321
将前一半加一填入后一半：12421
将前一半减一填入后一半：12221
下边界：9999
上边界：100001
从这五个数里面选取不等于原数的，且与原数差距最小的最小的数即为答案。
*/
vector<long> getCandidates(string n){
    int len = n.length();
    vector<long> candidates={
            (long)pow(10,len-1)-1,
            (long)pow(10,len)+1
    };
    long prefix = stol(n.substr(0,(len+1)/2));
    for (long i : {prefix-1,prefix,prefix+1}) {
        string tmp_prefix = to_string(i);
        string candidate = tmp_prefix + string(tmp_prefix.rbegin() + (len & 1),tmp_prefix.rend());
        candidates.emplace_back(stol(candidate));
    }
    return candidates;
}
string nearestPalindromic(string n) {
    long selfnumber = stol(n);
    long ans=-1;
    vector<long> candidates = getCandidates(n);
    for (auto candidate : candidates) {
        if (candidate != selfnumber){
            if (ans == -1 || abs(candidate-selfnumber) < abs(ans - selfnumber) ||abs(candidate-selfnumber) ==
            abs(ans - selfnumber) && candidate < ans){
                ans = candidate;
            }
        }
    }
    return to_string(ans);
}
