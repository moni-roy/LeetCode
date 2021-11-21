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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) return nullptr;
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
    TreeNode* buildTree(vector<int>& inorder, int in_left, int in_right, vector<int>& postorder, int post_left, int post_right) {
        if (in_left > in_right || post_left > post_right) return nullptr;
        int root_val = postorder[post_right];
        TreeNode* root = new TreeNode(root_val);
        int root_index = inorder[in_left];
        int left_size = 0;
        for (int i = in_left; i <= in_right; i++) {
            if (inorder[i] == root_val) {
                root_index = i;
                break;
            }
        }
        left_size = root_index - in_left;
        root->left = buildTree(inorder, in_left, root_index - 1, postorder, post_left, post_left + left_size - 1);
        root->right = buildTree(inorder, root_index + 1, in_right, postorder, post_left + left_size, post_right - 1);
        return root;
    }
};