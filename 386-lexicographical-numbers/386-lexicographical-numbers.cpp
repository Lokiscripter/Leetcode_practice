//
// Created by loki on 2022/4/18.
//

#include "../common.h"

/*
0
|
-----------------------------------
|       |       |       | | | | | |
1       2       3       4 5 6 7 8 9
|       |       |       | | | | | |
10~19   20~29   30~39   ............

就是个十叉树，先序遍历 DFS，
*/
void dfs(int k,int n,vector<int>& ans){
    if (k > n){
        return;
    }
    ans.emplace_back(k);
    if (k*10 > n){
        return;
    }
    for (int i = 0; i <= 9; ++i) {
        dfs(k*10+i,n,ans);
    }
}
vector<int> lexicalOrder(int n) {
    vector<int> ans;
    for (int i = 1; i <= 9; ++i) {
        dfs(i,n,ans);
    }
    return ans;
}