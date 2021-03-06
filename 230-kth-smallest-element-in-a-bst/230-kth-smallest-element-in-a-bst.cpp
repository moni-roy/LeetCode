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
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (--k == 0) return root->val;
            root = root->right;
        }
        return -1;
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