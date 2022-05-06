//
// Created by loki on 2022/5/6.
//

#include "../common.h"

class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {}

    // 维护一个队列，如果超出了3000毫秒的范围，就出队，最后返回队列的size
    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};