//
// Created by loki on 2022/5/11.
//

#include "../common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 297类似，BST就多了个特性，后序遍历是有序的，但题目其实用不到，反序列化也是先序
class Codec {
public:

    int idx = 0;
    int n;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr){
            return "";
        }
        string s = to_string(root->val)+',';
        s += serialize(root->left)+',';
        s += serialize(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string &data) {
        n = data.size();
        if ( idx >= n){
            return nullptr;
        }
        string num="";
        while (idx < n && data[idx] != ','){
            num += data[idx];
            idx ++;
        }
        ++ idx; // 跳过逗号
        if (num == ""){
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(num));
        root->left = deserialize(data);
        root->right = deserialize(data);
        return root;
    }
};