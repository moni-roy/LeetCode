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
        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorder_map);
    }
    
    TreeNode* buildTree(vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int post_start, int post_end, unordered_map<int, int>& inorder_map) {
        if (in_start > in_end) return nullptr;
        TreeNode* root = new TreeNode(postorder[post_end]);
        int root_index = inorder_map[postorder[post_end]];
        int left_size = root_index - in_start;
        root->left = buildTree(inorder, in_start, root_index - 1, postorder, post_start, post_start + left_size - 1, inorder_map);
        root->right = buildTree(inorder, root_index + 1, in_end, postorder, post_start + left_size, post_end - 1, inorder_map);
        return root;
    }
};