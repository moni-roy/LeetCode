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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, bool> mp;
        return dfs(root, k, mp);
    }
private:
    bool dfs(TreeNode* root, int k, unordered_map<int, bool> &mp) {
        if (!root) return false;
        if (mp.find(k - root->val) != mp.end()) return true;
        mp[root->val] = true;
        return dfs(root->left, k, mp) || dfs(root->right, k, mp);
    }
};