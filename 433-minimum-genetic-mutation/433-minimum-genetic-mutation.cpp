//
// Created by loki on 2022/5/7.
//

#include "../common.h"

// 单向BFS
int minMutation(string start, string end, vector<string>& bank) {
    // 1：判断极端情况
    if(start.empty()||end.empty()||bank.empty())return -1;
    if(find(bank.begin(),bank.end(),end)==bank.end())return -1;// 目标基因不在基因库中

    int step = 1;
    queue<string> q;
    q.push(start);
    vector<int> visit(bank.size(),0);
    while (!q.empty()){
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            string s = q.front();
            q.pop();
            for (int j = 0; j < bank.size(); ++j) { // 遍历整个基因库，访问未标记的基因；找到某个字符变异的基因添加标记，并进入队列即可
                if (visit[j] == 0){
                    int diff = 0;
                    for (int k = 0; k < s.size(); ++k) {
                        if (s[k] != bank[j][k]) { // calculate diff
                            diff++;
                        }
                    }
                    if (diff == 1) {
                        if (bank[j] == end) { // 若该下标j代表的基因为目标基因，则直接返回步长
                            return step;
                        }
                        visit[j] = 1; // 标记下标为j的基因已访问
                        q.push(bank[j]);
                    }
                }
            }
        }
        step++;
    }
    return -1;
}

