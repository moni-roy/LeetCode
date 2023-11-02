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
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        dfs(root, res);
        return res;
    }
private:
    pair<int, int> dfs(TreeNode* root, int& res) {
        if(!root) return {0, 0};
        auto left = dfs(root->left, res);
        auto right = dfs(root->right, res);
        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;
        if(root->val == round(sum / cnt)) res += 1;
        return {sum, cnt};
    }
};