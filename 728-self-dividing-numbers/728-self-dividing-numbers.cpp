//
// Created by loki on 2022/3/31.
//
#include "../common.h"
class Solution_728 {
public:
    bool IsSelfDividing(int num){
        int temp = num;
        while (temp > 0){
            int digit = temp % 10;
            if (digit == 0 || num % digit != 0){
                return false;
            }
            temp /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i < right+1; ++i) {
            if (IsSelfDividing(i)){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};