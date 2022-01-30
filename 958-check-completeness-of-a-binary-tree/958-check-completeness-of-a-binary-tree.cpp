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
        return usingBFS(root);
        
        // using DFS
        long long count = 0, maxIdx = 0;
        usingDFS(root, 1, count, maxIdx);
        return count == maxIdx;
    }
private:
    bool usingBFS(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty() && q.front() != nullptr) {
            TreeNode* cur = q.front();
            q.pop();
            q.push(cur->left);
            q.push(cur->right);
        }
        while(!q.empty() && q.front() == nullptr) {
            q.pop();
        }
        return q.empty();
    }
    void usingDFS(TreeNode* root, long long idx, long long& count, long long& maxIdx) {
        if(!root) return ;
        maxIdx = max(maxIdx, idx);
        count++;
        if(root->left && idx < INT_MAX) usingDFS(root->left, idx * 2, count, maxIdx);
        if(root->right && idx < INT_MAX) usingDFS(root->right, idx * 2 + 1, count, maxIdx);
    }
};