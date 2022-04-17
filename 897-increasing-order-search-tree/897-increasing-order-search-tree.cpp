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
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> inorder;
        dfs(root, inorder);
        TreeNode *ans = new TreeNode(0);
        TreeNode *head = ans;
        for(auto v: inorder) {
            ans->right = new TreeNode(v);
            ans = ans->right;
        }
        return head->right;
    }
    
    void dfs(TreeNode *root, vector<int> &v) {
        if(!root) return;
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }
};