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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return kthSmallest(root, k, cnt);
    }
private:
    int kthSmallest(TreeNode* root, int k, int& cnt) {
        if (!root) return 0;
        int left = kthSmallest(root->left, k, cnt);
        if (cnt == k) return left;
        cnt++;
        if (cnt == k) return root->val;
        int right = kthSmallest(root->right, k, cnt);
        if (cnt == k) return right;
        return 0;
    }
};