//
// Created by loki on 2022/3/29.
//

#include "../common.h"

// 滑动窗口，窗口的最大值就是结果，可以参考1004题
int maxConsecutiveChar(string &answerKey,int k,char c){
    int n = answerKey.length();
    int ans = 0;
    for (int left=0, right=0,sum = 0; right < n; right++) {
        if (answerKey[right] != c){
            sum += 1;
        }
        while (sum > k){
            if (answerKey[left] != c){
                sum -= 1;
            }
            left++;
        }
        ans = max(ans,right - left +1);
    }
    return ans;
}

int maxConsecutiveAnswers(string answerKey, int k){
    return max(maxConsecutiveChar(answerKey,k,'T'), maxConsecutiveChar(answerKey,k,'F'));
}