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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        usingDFS(root, ans, to_string(root->val));
        return ans;
    }
private:
    void usingDFS(TreeNode *root, vector<string> &ans, string cur) {
        if(!root->left && !root->right) {
            ans.push_back(cur);
            return;
        }
        if(root->left) usingDFS(root->left, ans, cur+"->"+to_string(root->left->val));
        if(root->right) usingDFS(root->right, ans, cur+"->"+to_string(root->right->val));
    }
};