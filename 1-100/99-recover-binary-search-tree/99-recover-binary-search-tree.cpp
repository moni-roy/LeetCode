/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr, *first = nullptr, *second = nullptr;
        inorder(root, prev, first, second);
        if (first && second) {
            int tmp = first->val;
            first->val = second->val;
            second->val = tmp;
        }
    }
private:
    void inorder(TreeNode *root, TreeNode *&prev, TreeNode *&first, TreeNode *&second) {
        if (!root) return;
        inorder(root->left, prev, first, second);
        if (prev && prev->val > root->val) {
            if (!first) first = prev;
            second = root;
        }
        prev = root;
        inorder(root->right, prev, first, second);
    }
};