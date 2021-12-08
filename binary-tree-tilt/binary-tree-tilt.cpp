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
    int sum = 0;
    int findTilt(TreeNode* root) {
        sum = 0;
        dfs(root);
        return sum;
    }
    int dfs(TreeNode *root) {
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        sum += abs(left - right);
        return left + root->val + right;
    }
};