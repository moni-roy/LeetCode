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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode *newRoot = new TreeNode(val);
        if (depth == 1) {
            newRoot->left = root;
            return newRoot;
        }
        queue<TreeNode*> q;
        q.push(root);
        int d = 1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (d == depth - 1) {
                    TreeNode *left = node->left;
                    TreeNode *right = node->right;
                    node->left = new TreeNode(val);
                    node->right = new TreeNode(val);
                    node->left->left = left;
                    node->right->right = right;
                } else {
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
            }
            d++;
        }
        return root;
    }
};