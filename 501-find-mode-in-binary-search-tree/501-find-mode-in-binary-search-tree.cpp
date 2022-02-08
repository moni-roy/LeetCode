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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> freq;
        int mx = 0;
        dfs(root, freq, mx);        
        vector<int> res;
        for (auto& p : freq) {
            if (p.second == mx) {
                res.push_back(p.first);
            }
        }
        return res;
    }
private:
    void dfs(TreeNode* root, unordered_map<int, int>& freq, int& mx) {
        if (!root) return;
        freq[root->val]++;
        mx = max(mx, freq[root->val]);
        dfs(root->left, freq, mx);
        dfs(root->right, freq, mx);
    }
};