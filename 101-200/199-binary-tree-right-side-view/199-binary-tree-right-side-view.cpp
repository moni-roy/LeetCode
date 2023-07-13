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
    vector<int> rightSideView(TreeNode* root) {    
        vector<int> res;
        if(root == nullptr)
            return res;
        rightSideView(root, res, 0);
        return res;
    }
private:
    void rightSideView(TreeNode* root, vector<int>& res, int depth)
    {
        if(root == nullptr)
            return;
        if(depth == res.size())
            res.push_back(root->val);
        rightSideView(root->right, res, depth + 1);
        rightSideView(root->left, res, depth + 1);
    }
};