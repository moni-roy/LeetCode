/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        return usingDFS(root, target, k);
    }
private:
    vector<int> usingDFS(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        // find the parent for each node
        dfs(root, nullptr, 0, parent);
        
        vector<int> res;
        unordered_set<TreeNode*> visited;
        // find all the node
        dfs(target, 0, parent, res, k, visited);
        return res;
    }
    void dfs(TreeNode* root, TreeNode* parent, int depth, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if (!root) return;
        parentMap[root] = parent;
        dfs(root->left, root, depth + 1, parentMap);
        dfs(root->right, root, depth + 1, parentMap);
    }
    void dfs(TreeNode* root, int depth, unordered_map<TreeNode*, TreeNode*>& parentMap, vector<int>& res, int k, unordered_set<TreeNode*>& visited) {
        if (!root) return;
        if (visited.count(root)) return;
        if (depth == k) {
            res.push_back(root->val);
            return;
        }
        visited.insert(root);
        // to left child
        dfs(root->left, depth + 1, parentMap, res, k, visited);
        // to right child
        dfs(root->right, depth + 1, parentMap, res, k, visited);
        // one is to parent
        dfs(parentMap[root], depth + 1, parentMap, res, k, visited);
    }
};