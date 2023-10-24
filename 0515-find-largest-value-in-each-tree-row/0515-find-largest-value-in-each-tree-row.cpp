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
    vector<int> largestValues(TreeNode* root) {
        vector <int> values;
        dfs(root, 0, values);
        return values;
    }
private:
    void dfs(TreeNode* root, int depth, vector<int> &values) {
        if (root == nullptr) return;
        if (depth == values.size()) {
            values.push_back(root->val);
        } else {
            values[depth] = max(root->val, values[depth]);
        }
        dfs(root->left, depth + 1, values);
        dfs(root->right, depth + 1, values);
    }
};