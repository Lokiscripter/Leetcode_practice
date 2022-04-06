//
// Created by loki on 2022/4/6.
//

#include "../common.h"

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if (n == 1){
            res.push_back(0);
            return res;
        }

        vector<int> degree(n,0); // 度表
        vector<vector<int>> tree(n);

        // 更新度，构建树
        for (int i = 0; i < edges.size(); ++i) {
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
            tree[edges[i][0]].push_back(edges[i][1]); // 构建树
            tree[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int> q;
        // 取出叶子节点
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1){ //度为1就是叶子节点，因为只可能别人指向它
                q.push(i);
            }
        }
        // bfs
        while(!q.empty()){
            int size = q.size();
            res.clear(); // 每次循环都要clear，保存最终的最小高度树结果，越靠近里面的节点作为跟，h最小，因此从叶子节点开始BFS
            for (int i = 0; i < size; ++i) {
                int cur = q.front();
                q.pop();
                res.push_back(cur);
                // 剪枝
                degree[cur] --;
                for (auto node : tree[cur]) { // 以cur作为根节点的子节点
                    degree[node] --;
                    if (degree[node] == 1){ // 新的叶子节点放到队列
                        q.push(node);
                    }
                }
            }
        }
        return  res;
    }
};