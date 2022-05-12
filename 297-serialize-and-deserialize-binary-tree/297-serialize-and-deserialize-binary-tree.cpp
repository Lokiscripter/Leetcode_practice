//
// Created by loki on 2022/5/12.
//

#include "../common.h"
#include <sstream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr){
            return "#";
        }
        string s = to_string(root->val)+' ';
        s += serialize(root->left)+' ';
        s += serialize(root->right);
        return s;
    }

    TreeNode* mydeserialize(istringstream &ss){
        string tmp;
        ss >> tmp;
        if (tmp == "#"){
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(tmp));
        root->left = mydeserialize(ss);
        root->right = mydeserialize(ss);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return mydeserialize(ss);
    }
};