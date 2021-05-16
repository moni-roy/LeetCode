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
    int ans = 0;
    int minCameraCover(TreeNode* root) {
        ans = 0;
        return cover(root)==0?++ans:ans;
    }
    
    int cover(TreeNode* root) {
        if(root==nullptr) return 1;
        int l = cover(root->left);
        int r = cover(root->right);
        
        if(l == 0 || r == 0) {
            ans ++;
            return 2;
        }
        if(l == 2 || r == 2) {
            return 1;
        }
        return 0;
    }
};