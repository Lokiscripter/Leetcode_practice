//
// Created by loki on 2022/4/9.
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

class Solution {
public:
    // BFS,如果要按每一层输出，那就要有个队列长度的循环把每一层作为一个结果压入ans
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr){
            return {};
        }
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        ans.emplace_back(vector<int>(1,root->val));
        while (!q.empty()){
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; ++i) {
                Node *node = q.front();
                q.pop();
                for (auto &n : node->children) {
                    q.push(n);
                    temp.emplace_back(n->val);
                }
            }
            if(!temp.empty())ans.emplace_back(temp);
        }
        return ans;
    }
};