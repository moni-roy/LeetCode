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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res = verticalTraversalUsingBFS(root);
        return res;
    }
private:
    vector<vector<int>> verticalTraversalUsingBFS(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int size = q.size();
            unordered_map<int, vector<int>> tmp;
            for (int i = 0; i < size; i++) {
                auto [node, col] = q.front();
                q.pop();
                tmp[col].push_back(node->val);
                if (node->left) q.push({node->left, col - 1});
                if (node->right) q.push({node->right, col + 1});
            }
            for (auto [col, v] : tmp) {
                sort(v.begin(), v.end());
                m[col].insert(m[col].end(), v.begin(), v.end());
            }
        }
        for (auto [col, v] : m) {
            // sort(v.begin(), v.end());
            res.push_back(v);
        }
        return res;
    }
};