//
// Created by loki on 2022/3/25.
//

#include "../common.h"


// 普通方法
class Solution {
public:
    int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};

    int calAverage(int i, int j, vector<vector<int>>& img)
    {
        int n = img.size();
        int m = img[0].size();
        vector<int> nums;
        nums.push_back(img[i][j]);
        for (int k = 0; k < 8; ++k) {
            int idx = i + dx[k];
            int idy = j + dy[k];
            if ( idx >= 0 && idx < n && idy >= 0 && idy < m){
                nums.push_back(img[idx][idy]);
            }
        }
        double num = double(accumulate(nums.begin(),nums.end(),0));
        return floor(num / nums.size());
    }

    vector<vector<int>> imageSmoother(vector<vector<int>>& img)
    {
        int n = img.size();
        int m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ans[i][j] = calAverage(i,j,img);
            }
        }
        return ans;
    }
};