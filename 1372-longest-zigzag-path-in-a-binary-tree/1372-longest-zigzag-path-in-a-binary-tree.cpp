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
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        dfs(root, ans, false, 0);
        dfs(root, ans, true, 0);
        return ans;
    }
private:
    void dfs(TreeNode* root, int& ans, bool left, int step) {
        if (!root) return;
        ans = max(ans, step);
        if (left) {
            dfs(root->left, ans, true, 1);
            dfs(root->right, ans, false, step + 1);
        } else {
            dfs(root->left, ans, true, step + 1);
            dfs(root->right, ans, false, 1);
        }
    }
};
