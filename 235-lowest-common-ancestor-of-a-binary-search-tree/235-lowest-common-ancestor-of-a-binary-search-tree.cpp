/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestorBST(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) {
            return root;
        }
        if(root->val > p->val && root->val > q->val) {
            return lowestCommonAncestorBST(root->left, p, q);
        }
        if(root->val < p->val && root->val < q->val) {
            return lowestCommonAncestorBST(root->right, p, q);
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) {
            return root;
        }
        auto l = lowestCommonAncestor(root->left, p, q);
        auto r = lowestCommonAncestor(root->right, p, q);
        
        return !l ? r : !r ? l : root;   
    }
};