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
    int minDiffInBST(TreeNode* root) {
        vector<int> inorder;
        inorder_traversal(root, inorder);
        int min_diff = INT_MAX;
        for (int i = 1; i < inorder.size(); i++) {
            min_diff = min(min_diff, inorder[i] - inorder[i - 1]);
        }
        return min_diff;
    }
private:
    void inorder_traversal(TreeNode* root, vector<int>& inorder) {
        if (root == nullptr) {
            return;
        }
        inorder_traversal(root->left, inorder);
        inorder.push_back(root->val);
        inorder_traversal(root->right, inorder);
    }
};