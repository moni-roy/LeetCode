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
    int id = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        
        for(int i = 0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        
        return dfs(preorder, mp, 0, preorder.size()-1);
    }
    
    TreeNode *dfs(vector<int>&pr, unordered_map<int,int> &mp, int l, int r) {
        if(l>r) return nullptr;
        
        int t = pr[id++];
        TreeNode *root = new TreeNode(t);
        
        root->left = dfs(pr, mp, l, mp[t]-1);
        root->right = dfs(pr, mp, mp[t]+1, r);
        return root;
    }
};