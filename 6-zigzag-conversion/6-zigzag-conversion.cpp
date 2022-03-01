//
// Created by loki on 2022/3/1.
//

#include "../common.h"

// https://leetcode-cn.com/problems/zigzag-conversion/solution/zzi-xing-bian-huan-by-jyd/
string convert(string s, int numRows){
    if(numRows==1)
        return s;
    vector<string> rows(min(numRows,int(s.size())));
    int curRow = 0;
    bool goingDown = false;
    for (char c:s) {
        rows[curRow]+=c;
        if (curRow == 0 || curRow == numRows-1){
            goingDown = !goingDown; // 翻转
        }
        curRow += (goingDown ? 1: -1); // 当前行号移动
    }
    string ans;
    for (int i = 0; i < rows.size(); ++i) {
        ans += rows[i];
    }
    return ans;
}