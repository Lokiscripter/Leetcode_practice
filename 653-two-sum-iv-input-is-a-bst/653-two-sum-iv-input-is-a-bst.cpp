//
// Created by loki on 2022/3/21.
//

#include "../common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_set<int> hashSet;
bool findTarget(TreeNode* root, int k){
    if (root == nullptr){
        return false;
    }
    if (hashSet.count(k-root->val)){
        return true;
    }
    hashSet.insert(root->val);
    return findTarget(root->left,k) || findTarget(root->right,k);
}