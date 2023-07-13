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
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        vector<int> cnt(10);
        dfs(root, cnt, ans);
        return ans;
    }
private:
    void dfs(TreeNode* root, vector<int>& cnt, int& ans) {
        if (root == nullptr) return;
        cnt[root->val]++;
        if (root->left == nullptr && root->right == nullptr) {
            int odd = 0;
            for (int i = 1; i <= 9; i++) {
                if (cnt[i] % 2 == 1) odd++;
            }
            if (odd <= 1) ans++;
        }
        dfs(root->left, cnt, ans);
        dfs(root->right, cnt, ans);
        cnt[root->val]--;
    }
};