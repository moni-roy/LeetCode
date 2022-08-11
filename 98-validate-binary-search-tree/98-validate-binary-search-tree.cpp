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
    bool isValidBST(TreeNode* root, long long l = -1e10, long long r = 1e10) {
        if (root) {
            if (root->val <= l || root->val >= r) return false;
            return isValidBST(root->left, l, root->val) & isValidBST(root->right, root->val, r);
        }
        return true;
    }
};