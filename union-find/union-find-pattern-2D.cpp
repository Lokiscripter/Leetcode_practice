//
// Created by loki on 2022/3/28.
//

#include "../common.h"

class UF_2D{
public:
    UF_2D(int n): count(0){}

    void merge(int p,int q){
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ){
            return;
        }
        if (size[rootQ] < size[rootP]){
            swap(rootQ,rootP);
        }
        parent[rootP] = rootQ;
        size[rootQ] += size[rootP];
        count--;
    }

    int get_count() const{
        return this->count;
    }

private:
    unordered_map<int,int> parent,size;
    int count;
    int find(int x){
        if (parent.count(x) == 0){
            parent[x] = x;
            count++;
        }
        if (x!=parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
};