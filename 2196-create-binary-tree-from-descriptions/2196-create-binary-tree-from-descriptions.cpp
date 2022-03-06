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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        if (descriptions.empty()) {
            return nullptr;
        }
        unordered_map<int, TreeNode*> nodes, parents;
        for (auto& description : descriptions) {
            int val = description[0];
            int left = description[1];
            int isLeft = description[2];
            if (nodes.find(val) == nodes.end()) {
                nodes[val] = new TreeNode(val);
            }
            if (nodes.find(left) == nodes.end()) {
                nodes[left] = new TreeNode(left);
            }
            if (isLeft) {
                nodes[val]->left = nodes[left];
            } else {
                nodes[val]->right = nodes[left];
            }
            parents[left] = nodes[val];
        }
        for (auto& node : nodes) {
            if (parents.find(node.first) == parents.end()) {
                return node.second;
            }
        }
        return nullptr;
    }
};