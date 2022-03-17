//
// Created by loki on 2022/3/17.
//

#include "../common.h"

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> stk;
        int lastv = INT_MIN;
        for (int &num : preorder) {
            while (!stk.empty() && stk.top() < num) {
                lastv = stk.top(); // 每次出栈就更新上一个节点
                stk.pop();
            }
            if (num < lastv) return false; //局部递减，总体递增，如果入栈元素小于上一次出栈元素，那就说明不对
            stk.emplace(num);
        }
        return true;
    }
};