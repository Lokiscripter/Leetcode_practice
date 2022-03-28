//
// Created by loki on 2022/3/28.
//

#include "../common.h"

class UF {
public:
    UF(int n){
        this->count = n;
        parent.reserve(n);
        size.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    bool merge(int p,int q){
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ){
            return false;
        }
        if (size[rootQ] < size[rootP]){
            swap(rootQ,rootP);
        }
        parent[rootP] = rootQ;
        size[rootQ] += size[rootP];
        count--;
        return true;
    }

    bool connected(int p,int q){
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    int get_count() const{
        return this->count;
    }
private:
    // 连通分量个数
    int count;
    // 存储一棵树
    vector<int> parent;
    // 记录树的“重量”
    vector<int> size;

    int find(int x){
        return parent[x] == x ? x : find(parent[x]);
    }
};

