//
// Created by loki on 2022/5/8.
//

#include "../common.h"

// 方法一：取反
/*
 * 从起始位置进行遍历，每次将下标为 nums[i]−1 的数字取反；
 * 当遍历到值 nums[i] 为负数，需要忽略其负号。
 * 若发现下标为 nums[i]−1 的数字已经是负数，说明之前出现过同样的数字 nums[i]，即找到了重复数字；
 */
vector<int> findDuplicates(vector<int>& nums) {
    const int N = nums.size();
    vector<int> res;
    for (int i = 0; i < N; ++i) {
        if (nums[abs(nums[i])-1] < 0){
            res.push_back(abs(nums[i]));
        }
        nums[abs(nums[i])-1] *= -1;
    }
    return res;
}

// 方法二：增加偏移量
/*
 * 由于本题数字范围是1到100000，因此可以加一个100000的偏移量，映射到一个新的数组空间
 * 从起始位置进行遍历，每次将下标为 nums[i]−1的数字 + 100000;
 * 遍历到值 nums[i]超过 100000，需要将其 −100000 恢复原值；
 * 若发现下标为 nums[i]−1 的数字已经超过 100000，说明之前出现过同样的数字 nums[i]，即找到了重复数字；
 */
vector<int> findDuplicates2(vector<int>& nums) {
    vector<int> res;
    for (int num : nums) {
        if (nums[(num % 100000) - 1] > 100000){
            res.push_back(nums[num % 100000]);
        }
        nums[(num % 100000) - 1] += 100000;
    }
    return res;
}