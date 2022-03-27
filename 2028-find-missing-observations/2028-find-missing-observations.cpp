//
// Created by loki on 2022/3/27.
//

#include "../common.h"

vector<int> missingRolls(vector<int>& rolls, int mean, int n){
    int rolls_sum = accumulate(rolls.begin(),rolls.end(),0);
    int m = rolls.size();
    int sum = mean * (n + m);
    int other_sum = sum-rolls_sum;
    if (n * 6 < other_sum || n * 1 > other_sum){
        return {};
    }
    int num = other_sum / n;
    int last_num = other_sum % n;
    if (last_num + num > 6){
        vector<int> ans(n,num);
        for (int i = 0; i < last_num; ++i) {
            ans[i] += 1;
        }
        return ans;
    } else{
        vector<int> ans(n-1,num);
        ans.push_back(num + last_num);
        return ans;
    }
}