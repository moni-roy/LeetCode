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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return nullptr;
        TreeNode *root = new TreeNode((root1 ? root1->val : 0) + (root2 ? root2->val : 0));
        if((root1 && root1->left) || (root2 && root2->left)) {
            root->left = mergeTrees((root1 && root1->left) ? root1->left : nullptr, (root2 && root2->left) ? root2->left : nullptr);
        }
        if((root1 && root1->right) || (root2 && root2->right)) {
            root->right = mergeTrees((root1 && root1->right) ? root1->right : nullptr, (root2 && root2->right) ? root2->right : nullptr);
        }
        return root;
    }
};