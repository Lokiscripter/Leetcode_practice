//
// Created by loki on 2022/3/25.
//

#include "../common.h"

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> f(n+1,vector<int>(m+1,0)); // 前缀和数组，从1开始计数
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j) {
                f[i][j] = f[i-1][j]+f[i][j-1]-f[i-1][j-1]+img[i-1][j-1];
            }
        vector<vector<int>> res(n,vector<int>(m));
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j) {
                int x1 = max(i-2, 0); int y1 = max(j-2, 0);
                int x2 = min(i+1, n); int y2 = min(j+1, m);
                res[i-1][j-1] = (f[x2][y2] - f[x1][y2] - f[x2][y1] + f[x1][y1])
                                / ((y2-y1)*(x2-x1));
            }
        return res;
    }
};

// 二维前缀和模板
class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = n == 0 ? 0 : matrix[0].size();
        // 与「一维前缀和」一样，前缀和数组下标从 1 开始，因此设定矩阵形状为 [n + 1][m + 1]（模板部分）
        sum.resize(n+1, vector<int>(m+1,0));
        // 预处理除前缀和数组（模板部分)
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }

    int sumRegion(int x1, int y1, int x2, int y2) {
        // 求某一段区域和 [i, j] 的模板是 sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];（模板部分）
        // 但由于我们源数组下标从 0 开始，因此要在模板的基础上进行 + 1
        x1++; y1++; x2++; y2++;
        return sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1];
    }
};