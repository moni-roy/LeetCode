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
    int widthOfBinaryTree(TreeNode* root) {
        unordered_map<int, unsigned long long> firstIndex;
        return dfs(root, 0, 0, firstIndex);
    }
private:
    unsigned long long dfs(TreeNode* root, int level, unsigned long long index, unordered_map<int, unsigned long long>& firstIndex) {
        if(!root) return 0;
        if(firstIndex.find(level) == firstIndex.end()) {
            firstIndex[level] = index;
        }
        unsigned long long left = dfs(root->left, level + 1, 2 * index, firstIndex);
        unsigned long long right = dfs(root->right, level + 1, 2 * index + 1, firstIndex);
        return max(index - firstIndex[level] + 1, max(left, right));
    }
};