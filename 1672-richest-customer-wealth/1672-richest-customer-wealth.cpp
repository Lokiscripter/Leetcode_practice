//
// Created by loki on 2022/4/14.
//

#include "../common.h"

int maximumWealth(vector<vector<int>>& accounts) {
    int ans = 0;
    for (int i = 0; i < accounts.size(); ++i) {
        ans = max(ans, accumulate(accounts[i].begin(),accounts[i].end(),0));
    }
    return ans;
}