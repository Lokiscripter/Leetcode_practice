//
// Created by loki on 2022/3/20.
//

#include "../common.h"

int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience)
{
    int n = patience.size();
    int Max = 0;
    vector<vector<int>> graph(n);
    for (auto &e : edges) { // 构建无向图
        graph[e[0]].emplace_back(e[1]);
        graph[e[1]].emplace_back(e[0]);
    }
    vector<int> dist(n); // 记录每个服务器到主服务器的最短距离
    queue<int> que;
    que.emplace(0);
    while(!que.empty()){ // BFS
        int u = que.front();
        que.pop();
        for (auto v : graph[u]) { // 新节点不是0节点，并且没有访问过
            if (v && !dist[v]){ //记录新节点的距离
                dist[v] = dist[u] + 1;
                que.emplace(v);
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        int di = 2 * dist[i],t = patience[i],sum;// 当前服务器的往返时间t为两倍到主服务器距离
        if (di <= patience[i]){ // 往返时间t不超过可等待时间，则该服务器从(di+1)sum变为空闲
            sum = di;
        }else{ // 往返时间t超过可等待时间，则该服务器从(di+最后1次消息传输时间)sum变为空闲
            sum = di + (di-1)/t * t;
        }
        Max = max(Max,sum); // 更新最大变为空闲状态的秒数
    }
    return Max+1;//回来之后一秒才变为空闲
}