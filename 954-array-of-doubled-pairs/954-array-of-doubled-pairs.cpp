//
// Created by loki on 2022/4/1.
//

#include "../common.h"

class Solution {
public:
/*
    设 arr 的长度为 n，题目本质上是问 arr 能否分成 n/2对元素，每对元素中一个数是另一个数的两倍。
    设 cnt[x] 表示 arr 中 x 的个数。
    对于arr 中的 0，它只能与 0 匹配。如果 cnt[0] 是奇数，那么必然无法满足题目要求。
    去掉 arr 中的 0。设 xx 为 arr 中绝对值最小的元素，由于没有绝对值比 xx 更小的数，
    因此 x 只能与 2x 匹配。如果此时 cnt[2x]<cnt[x]，
    那么会有部分 x 无法找到它的另一半，即无法满足题目要求；
    否则将所有 x 和 cnt[x] 个 2x2x 从 arr 中去掉，继续判断剩余元素是否满足题目要求。
    不断重复此操作，如果某个时刻 arr 为空，则说明 arr 可以满足题目要求。
    代码实现时，我们可以用一个哈希表来统计 cnt，并将其键值按绝对值从小到大排序，
    然后模拟上述操作，去掉元素的操作可以改为从 cnt 中减去对应值。
 */
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> cnt;
        for (int i = 0; i < arr.size(); ++i) {
            cnt[arr[i]]++;
        }
        if (cnt[0] % 2 != 0){
            return false;
        }
        vector<int> ans;
        ans.reserve(ans.size());
        for (auto m : cnt) {
            ans.emplace_back(m.first);
        }
        sort(ans.begin(),ans.end(),[](int x,int y){
            return abs(x) < abs(y);
        });
        for (int x : ans) {
            if (cnt[2*x] < cnt[x]){
                return false;
            }
            cnt[2*x] -= cnt[x];
        }
        return true;
    }
};