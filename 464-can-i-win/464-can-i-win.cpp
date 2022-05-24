//
// Created by loki on 2022/5/24.
//

#include "../common.h"

// 记忆化递归+状态压缩优化
// 题解参考https://leetcode.cn/problems/can-i-win/solution/by-fuxuemingzhu-g16c/
class Solution {
private:
    // visited[i] == 0，说明没有计算过
    // visited[i] == 1，说明计算过，结果为 true
    // visited[i] == 2，说明计算过，结果为 false
    int visited[1<<21];
    // 二进制表示公共整数池里面的数字是否在游戏里使用过，比如state=18，二进制是10010，表示1和4已经使用过了（右边往左数）
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal){
            return true;
        }
        if (maxChoosableInteger * (maxChoosableInteger + 1)/2 < desiredTotal){
            return false;
        }
        return dfs(0,0,maxChoosableInteger,desiredTotal);
    }

    // 当前做选择的玩家是否一定赢
    bool dfs(int state,int sum,int maxChoosableInteger, int desiredTotal){
        if (visited[state] == 1) return true;
        if (visited[state] == 2) return false;
        for (int x = 1; x <= maxChoosableInteger; ++x) {
            if (1<<x & state) continue; // 如果x使用过了，就不能选择
            if (sum + x >= desiredTotal){ // 如果选择了 x 以后，大于等于了 desiredTotal，当前玩家赢
                visited[state] = 1;
                return true;
            }
            if (!dfs(1<<x|state,sum+x,maxChoosableInteger,desiredTotal)){ // 当前玩家选择了 x 以后，判断对方玩家是否一定输
                visited[state] = 1;
                return true;
            }
        }
        visited[state] = 2;
        return false;
    }

};