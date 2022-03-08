//
// Created by loki on 2022/3/8.
//

#include "../common.h"

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0;
    int right = 0;
    int ans = INT_MAX;
    int sum = 0; //记录前缀和
    while (right < n){
        sum += nums[right];
        right++;
        while (sum >= target){
            ans = min(ans,right-left); // 更新结果
            sum -= nums[left];
            left++;
        }
    }
    return ans == INT_MAX ? 0: ans;
}