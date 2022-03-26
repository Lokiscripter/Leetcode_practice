//
// Created by loki on 2022/3/26.
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

// 递归法
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr){
        return root;
    }
    swap(root->left,root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

// DFS非递归，用栈
TreeNode* invertTree_dsf(TreeNode* root) {
    if (root == nullptr){
        return root;
    }
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()){
        TreeNode* node = s.top();
        s.pop();
        swap(node->left,node->right);
        if (node->left!= nullptr){
            s.push(node->left);
        }
        if (node->right!= nullptr){
            s.push(node->right);
        }
    }
    return root;
}

// BFS非递归，用队列
TreeNode* invertTree_bfs(TreeNode* root) {
    if (root == nullptr){
        return root;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        swap(node->left,node->right);
        if (node->left!= nullptr){
            q.push(node->left);
        }
        if (node->right!= nullptr){
            q.push(node->right);
        }
    }
    return root;
}