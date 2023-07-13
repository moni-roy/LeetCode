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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size()==0) return nullptr;
        return BST(nums, 0, nums.size()-1);
    }
    
    TreeNode *BST(vector<int> &nums, int s, int e) {
        if(s>e) return nullptr;
        int m = (s+e)/2;
        TreeNode *node = new TreeNode(nums[m]);
        node->left = BST(nums, s, m-1);
        node->right = BST(nums, m+1, e);
        return node;
    }
};