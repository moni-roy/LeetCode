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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int> > ret;
        vector<int> path;
        backTrack(root, targetSum, path, ret);
        return ret;
    }
    
    void backTrack(TreeNode *root, int sum, vector<int> &path, vector<vector<int>> &ret) {
        if (!root) return;
        path.push_back(root->val);
        if (!(root->left) && !(root->right) && root->val == sum) ret.push_back(path);
        backTrack(root->left, sum - root->val, path, ret);
        backTrack(root->right, sum - root->val, path, ret);
        path.pop_back();
    }
};