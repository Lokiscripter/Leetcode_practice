//
// Created by loki on 2022/3/15.
//

#include "../common.h"

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        this->nums=nums;
        this->cnt=0;
        this->maxOr=0;
        for (int num:nums) {
            maxOr |= num;
        }
        dfs(0,0);
        return cnt;
    }
    void dfs(int pos,int orVal){
        if (orVal == maxOr){
            cnt += 1 << (nums.size()-pos);
            return;
        }
        if (pos == nums.size()){
            return;
        }
        dfs(pos+1,orVal | nums[pos]);
        dfs(pos+1,orVal);
    }

private:
    vector<int> nums;
    int maxOr, cnt;
};