//
// Created by loki on 2022/3/30.
//

#include "../common.h"

vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    vector<int> count(k,0); // 记录每个服务器各自服务了多少请求
    int n = arrival.size();
    int now = 0; // 当前时间
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> busy;
    set<int> free;
    for (int i = 0; i < k; ++i) {
        free.insert(i); // 初始时服务器都是空闲的
    }
    for (int i = 0; i < n; ++i) {
        now = arrival[i];
        while(!busy.empty() && busy.top().first <= now){
            free.insert(busy.top().second);
            busy.pop();
        }
        if (free.empty())   continue;

        // 分配服务器
        auto temp = free.lower_bound(i % k);
        if (temp == free.end()){
            temp = free.lower_bound(0); // 环形遍历
        }
        busy.push(make_pair(now+load[i],*temp));
        count[*temp] ++;
        free.erase(temp);
    }
    int max_times = *max_element(count.begin(),count.end());
    vector<int> ans;
    for (int i = 0; i < k; ++i) {
        if (count[i] == max_times){
            ans.push_back(i);
        }
    }
    return ans;
}