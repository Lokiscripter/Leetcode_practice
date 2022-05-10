//
// Created by loki on 2022/5/10.
//

#include "../common.h"

/*
 * 法一：模拟+队列
 * 每一轮游戏中，从当前小伙伴开始数 k 名小伙伴，数到的第 k 名小伙伴离开圈子。
 * 模拟游戏过程的做法是，将队首元素取出并将该元素在队尾处重新加入队列，重复该操作 k−1 次，则在 k−1 次操作之后，队首元素即为这一轮中数到的第 k 名小伙伴的编号，
 * 将队首元素取出，即为数到的第 k 名小伙伴离开圈子。上述操作之后，新的队首元素即为下一轮游戏的起始小伙伴的编号。
 * 每一轮游戏之后，圈子中减少一名小伙伴，队列中减少一个元素。重复上述过程，直到队列中只剩下 1 个元素，该元素即为获胜的小伙伴的编号。
*/
int findTheWinner(int n, int k) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        q.emplace(i);
    }
    while (q.size() > 1){
        for (int i = 1; i < k; ++i) {
            q.emplace(q.front());
            q.pop();
        }
        q.pop();
    }
    return q.front();
}

/*
 * 法二：约瑟夫环问题
 * 推导参考：https://leetcode.cn/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/javajie-jue-yue-se-fu-huan-wen-ti-gao-su-ni-wei-sh/
 * 由结果反推，倒推最后剩下的数字在最开始数组中的位置
 * 每轮推导的公式是(当前index + m) % 上一轮剩余数字的个数
 * 源自于 剑指 Offer 62
 */

int findTheWinner2(int n, int k) {
    int pos = 0;
    for (int i = 2; i <= n; ++i) { // 起始是2是因为最后一轮的上一轮剩下2个人，最开始是有n个人，所以<= n
        pos = (pos + k) % i;
    }
    return pos + 1; // 从1开始的
}