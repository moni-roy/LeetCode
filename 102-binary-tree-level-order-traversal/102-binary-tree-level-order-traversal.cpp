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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        dfs(ret, root, 0);
        return ret;
    }
    void dfs(vector<vector<int> > &v, TreeNode *r, int l) {
        if (r == nullptr) return ;
        if (v.size() == l) {
            v.push_back(vector<int>());
        }
        v[l].push_back(r->val);
        dfs(v, r->left, l + 1);
        dfs(v, r->right, l + 1);
    }
};