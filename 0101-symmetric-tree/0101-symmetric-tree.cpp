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
    bool isSymmetric(TreeNode* root) {
        vector<int> lr, rl;
        inOrder(root->left, lr, true);
        inOrder(root->right, rl, false);
        if (lr.size() != rl.size()) return false;
        for (int i = 0; i < lr.size(); i++) if(lr[i] != rl[i]) return false;
        return true;
    }
    
    void inOrder(TreeNode* root, vector<int> &v, bool isLR) {
        if (!root) {
            v.push_back(-112);
            return;
        }
        if (isLR) inOrder(root->left, v, isLR);
        else inOrder(root->right, v, isLR);
        v.push_back(root->val);
        if (isLR) inOrder(root->right, v, isLR);
        else inOrder(root->left, v, isLR);
        v.push_back(-111);
        return;
    }
};