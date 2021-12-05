class Solution {
public:
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        vector<int> res = rob_helper(root);
        return max(res[0], res[1]);
    }

    vector<int> rob_helper(TreeNode* root) {
        if(root == nullptr) return vector<int>(2, 0);
        vector<int> left = rob_helper(root->left);
        vector<int> right = rob_helper(root->right);
        vector<int> res(2, 0);
        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = root->val + left[0] + right[0];
        return res;
    }
};