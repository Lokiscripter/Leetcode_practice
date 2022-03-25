//
// Created by loki on 2022/3/25.
//

#include "../common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr){
            if (slow->val != fast->val){
                // 类似 nums[slow] = nums[fast];
                slow->next = fast;
                // 类似 slow ++;
                slow = slow->next;
            }
            // 类似fast ++
            fast = fast->next;
        }
        slow->next = nullptr;
        return head;
    }
};