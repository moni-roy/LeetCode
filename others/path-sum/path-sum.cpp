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
    bool hasPathSum(TreeNode* root, int targetSum, int sum = 0) {
        if(!root) return false;
        if(sum + root->val == targetSum && !root->left && !root->right) return true;
        return hasPathSum(root->left, targetSum, sum + root->val) || hasPathSum(root->right, targetSum, sum + root->val);
    }
};