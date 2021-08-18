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
    int goodNodes(TreeNode* root, int pre = -100000) {
        if(root == nullptr) return 0;
        int ret = 0;
        if(pre <= root->val) ret = 1;
        pre = max(pre, root->val);
        ret += goodNodes(root->left, pre) + goodNodes(root->right, pre);
        return ret;
    }
};