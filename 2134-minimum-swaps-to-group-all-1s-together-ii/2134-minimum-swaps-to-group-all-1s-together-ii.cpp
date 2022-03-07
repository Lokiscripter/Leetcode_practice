//
// Created by loki on 2022/3/7.
//

#include "common.h"

// 前缀和+滑窗
int minSwaps(vector<int>& nums){
    int one_cnt = accumulate(nums.begin(),nums.end(),0);
    if (one_cnt == 0)   return 0;
    vector<int> record = nums;
    record.insert(record.end(),nums.begin(),nums.end());
    int ans = INT_MAX;
    int cnt = 0;
    for (int i = 0; i < record.size(); ++i) {
        if (record[i] == 1) cnt++;
        if (i >= one_cnt-1){
            ans = min(ans,one_cnt-cnt);
            if (record[i-one_cnt+1] == 1){
                cnt--;
            }
        }
    }
    return ans;
}