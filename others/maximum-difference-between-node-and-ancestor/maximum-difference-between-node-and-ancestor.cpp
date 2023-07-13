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
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        dfs(root, root->val, root->val, res);
        return res;
    }
    void dfs(TreeNode* root, int mn, int mx, int& res) {
        if (!root) return;
        mn = min(mn, root->val);
        mx = max(mx, root->val);
        res = max(res, mx - mn);
        dfs(root->left, mn, mx, res);
        dfs(root->right, mn, mx, res);
    }
};