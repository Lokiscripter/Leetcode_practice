//
// Created by loki on 2022/5/13.
//

#include "../common.h"

int minDeletionSize(vector<string>& strs) {
    int ans = 0;
    const int n = strs[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = strs.size() - 1; j > 0; j--) {
            if (strs[j][i] < strs[j-1][i]){
                ans++;
                break;
            }
        }
    }
    return ans;
}