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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        long long count = 0, maxIdx = 0;
        usingDFS(root, 1, count, maxIdx);
        // cout<<maxIdx<<" "<<count<<endl;
        return count == maxIdx;
    }
private:
    void usingDFS(TreeNode* root, long long idx, long long& count, long long& maxIdx) {
        if(!root) return ;
        maxIdx = max(maxIdx, idx);
        count++;
        if(root->left && idx < INT_MAX) usingDFS(root->left, idx * 2, count, maxIdx);
        if(root->right && idx < INT_MAX) usingDFS(root->right, idx * 2 + 1, count, maxIdx);
    }
};