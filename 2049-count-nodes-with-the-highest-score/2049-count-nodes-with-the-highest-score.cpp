//
// Created by loki on 2022/3/11.
//

#include "../common.h"

class Solution {
public:
    int n;
    vector<vector<int>> tree;   //  tree[i]表示节点i所有子节点
    long long best=0;
    int ans=0;

    // 返回值为节点i下所有节点数量（包括自己）
    // 顺便计算每个节点的得分
    int dfs(int node){
        long long score=1;  // 记录分数
        int cnt = 0;         // 记录子节点总数量 为每个子树的节点数量之和 加当前节点
        for (auto child:tree[node]) {
            // 计算每个子树的节点数量
            int branch = dfs(child);
            // 贡献得分
            score *= branch;
            // 累计子节点数量
            cnt += branch;
        }
        // 如果当前节点不是根节点 则父节点也成为了独立的树
        // 其贡献为节点总数减去当前子树下所有节点数量
        if (node){
            score *= (n-cnt-1);
        }
        if (score > best){
            ans = 1;
            best = score;
        } else if(score == best){
            ans++;
        }
        return cnt+1;
    }

    int countHighestScoreNodes(vector<int>& parents){
        n = parents.size();
        tree.resize(n, vector<int>());
        // 这里要从1开始，因为0的根节点是-1
        for (int i = 1; i < n; ++i) {
            tree[parents[i]].push_back(i);
        }
        dfs(0);
        return ans;
    }
};