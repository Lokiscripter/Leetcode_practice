//
// Created by loki on 2022/3/10.
//

#include "../common.h"

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

void preorder_dfs(vector<int> &res,Node* root){
    if (root == nullptr){
        return;
    }
    res.push_back(root->val);
    for (auto &child : root->children) {
        preorder_dfs(res,child);
    }
}
vector<int> preorder(Node* root){
    vector<int> ans;
    preorder_dfs(ans,root);
    return ans;
}