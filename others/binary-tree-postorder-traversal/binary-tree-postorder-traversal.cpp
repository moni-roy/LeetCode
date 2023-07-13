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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        dfs(root, ret);
        return ret;
    }
    
    void dfs(TreeNode *root, vector<int> &ret) {
        if(!root) return;
        dfs(root->left, ret);
        dfs(root->right, ret);
        ret.push_back(root->val);
    }
};