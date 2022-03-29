//
// Created by loki on 2022/3/29.
//

#include "../common.h"

int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;
    for (int left = 0,right = 0,sum = 0; right < n; ++right) {
        if (nums[right] != 1){
            sum += 1;
        }
        while (sum > k){
            if (nums[left] != 1){
                sum -= 1;
            }
            left++;
        }
        ans = max(ans,right-left+1);
    }
    return ans;
}