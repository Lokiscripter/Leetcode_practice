//
// Created by loki on 2022/4/12.
//

#include "../common.h"

vector<int> numberOfLines(vector<int>& widths, string s) {
    vector<int> ans(2,0);
    int sum = 0;
    int line = 1;
    int charactor = 0;
    for (char c:s) {
        if (sum > 100 - widths[c-'a']) {
            sum = widths[c - 'a'];
            line ++;
        }else{
            sum += widths[c - 'a'];
        }
    }
    ans[0] = line;
    ans[1] = sum;
    return ans;
}