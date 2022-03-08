//
// Created by loki on 2022/3/8.
//

#include "../common.h"

// 前缀和 + 滑窗
int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    vector<int> preSum(n,0);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        preSum[i] = sum;
    }
    if (preSum[n-1] < target){
        return 0;
    }
    int ans = INT_MAX;
    int left = -1;
    int right = 0;
    for (int i = 0; i < n; ++i) {
        while (right<n){
            int left_sum;
            int right_sum = preSum[right];
            right++;
            left >= 0 ? left_sum=preSum[left] : left_sum=0;
            while (right_sum - left_sum >= target){
                ans = min(ans,right-left-1);
                left++;
                left >= 0 ? left_sum=preSum[left] : left_sum=0;
            }
        }
    }
    return ans;
}