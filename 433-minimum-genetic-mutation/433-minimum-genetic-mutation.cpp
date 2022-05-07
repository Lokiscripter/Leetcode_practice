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

// 双向BFS，这时候不需要visited了，因为退出条件是q2里面包含q1的元素，也就是撞到一起了
int minMutation2(string start, string end, vector<string>& bank) {
    // 1：判断极端情况
    if(start.empty()||end.empty()||bank.empty())return -1;
    if(find(bank.begin(),bank.end(),end)==bank.end())return -1;// 目标基因不在基因库中

    unordered_set<string> q1;
    unordered_set<string> q2;
    q1.insert(start);
    q2.insert(end);
    int step = 0;;
    while (!q1.empty() && !q2.empty()){
        unordered_set<string> temp;
        for (string cur : q1) {
            if(q2.count(cur) > 0){
                return step;
            }
            for (int j = 0; j < bank.size(); ++j) { // 遍历整个基因库，访问未标记的基因；找到某个字符变异的基因添加标记，并进入队列即可
                    int diff = 0;
                    for (int k = 0; k < cur.size(); ++k) {
                        if (cur[k] != bank[j][k]) { // calculate diff
                            diff++;
                        }
                    }
                    if (diff == 1) {
                        temp.insert(bank[j]);
                    }
            }
        }
        /* 在这里增加步数 */
        step++;
        // temp 相当于 q1
        // 这里交换 q1 q2，下一轮 while 就是扩散 q2
        q1 = q2;
        q2 = temp;
    }
    return -1;
}