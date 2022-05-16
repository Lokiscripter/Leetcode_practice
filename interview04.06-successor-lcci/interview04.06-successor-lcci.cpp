//
// Created by loki on 2022/5/16.
//

#include "../common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 法一：为了找到二叉搜索树中的节点 p 的后继节点，最直观的方法是中序遍历。
// 由于只需要找到节点 p 的后继节点，因此不需要维护完整的中序遍历序列，只需要在中序遍历的过程中维护上一个访问的节点和当前访问的节点。
// 如果上一个访问的节点是节点 p，则当前访问的节点即为节点 p 的后继节点。
// 如果节点 p 是最后被访问的节点，则不存在节点 p 的后继节点，返回 null。
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    stack<TreeNode*> st;
    TreeNode* curr = root;
    TreeNode* prev = nullptr;
    while (!st.empty() || curr!= nullptr){
        while (curr != nullptr){
            st.emplace(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        if (prev == p){
            return curr;
        }
        prev = curr;
        curr = curr->right;
    }
    return nullptr;
}

// 法二：利用BST特性，不做中序遍历。
// 1、后继节点的节点值大于 p 的节点值；
// 2、后继节点是节点值大于 p 的节点值的所有节点中节点值最小的一个节点。
// 如果节点 p 的右子树不为空，则节点 p 的后继节点在其右子树中，在其右子树中定位到最左边的节点，即为节点 p 的后继节点。
// 如果节点 p 的右子树为空，则需要从根节点开始遍历寻找节点 p 的祖先节点
TreeNode* inorderSuccessor2(TreeNode* root, TreeNode* p) {
    TreeNode *successor = nullptr;
    if (p->right!= nullptr){
        successor = p->right;
        while (successor->left!= nullptr){
            successor = successor->left;
        }
        return successor;
    }
    TreeNode* node = root;
    while (node != nullptr){
        if (node->val>p->val){
            successor = node;
            node = node->left;
        }else{
            node = node->right;
        }
    }
    return successor;
}