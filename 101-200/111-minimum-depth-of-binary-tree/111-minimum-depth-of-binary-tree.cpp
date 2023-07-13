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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return DFS(root);
        return BFS(root);
    }
private:
    int DFS(TreeNode *root) {
        if(!root) return INT_MAX - 1;
        if(!root->left && !root->right) return 1;
        return 1 + min(DFS(root->left), DFS(root->right));
    }
    int BFS(TreeNode *root) {
        queue<TreeNode*> q;
        if(root) q.push(root);
        int depth = 0;
        while(!q.empty()){
            depth++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(!node->left && !node->right) return depth;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return depth;
    }
};