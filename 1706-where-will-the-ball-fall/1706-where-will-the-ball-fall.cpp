//
// Created by loki on 2022/3/3.
//

#include "../common.h"

// 1706. 球会落何处 https://leetcode-cn.com/problems/where-will-the-ball-fall/
int findBall_dfs(vector<vector<int>>& grid,int i,int j){
    if (j < 0 || j >= grid[0].size()){
        return -1;
    }
    if(grid[i][j] == 1 && j == grid[0].size()-1 ){
        return -1;
    }
    if (grid[i][j] == -1 && j == 0){
        return -1;
    }
    if (grid[i][j] == 1 && grid[i][j+1] == -1) {
        return -1;
    }
    if (grid[i][j] == -1 && grid[i][j-1] == 1){
        return -1;
    }
    if (i==grid.size()-1){
        return j+grid[i][j];
    }
    int next_i = i + 1;
    int next_j = j + grid[i][j];
    return findBall_dfs(grid,next_i,next_j);
}

vector<int> findBall(vector<vector<int>>& grid){
    vector<int> ans(grid[0].size(),-1);
    for (int j = 0; j < grid[0].size(); ++j) {
        ans[j] = findBall_dfs(grid,0,j);
    }
    return ans;
}