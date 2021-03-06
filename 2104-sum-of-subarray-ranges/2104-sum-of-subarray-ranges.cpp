//
// Created by loki on 2022/3/4.
//


#include "../common.h"


long long subArrayRanges(vector<int>& nums)
{
    int n = nums.size();
    long long ret = 0;
    for (int i = 0; i < n; i++) {
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int j = i; j < n; j++) {
            minVal = min(minVal, nums[j]);
            maxVal = max(maxVal, nums[j]);
            ret += maxVal - minVal;
        }
    }
    return ret;
}
