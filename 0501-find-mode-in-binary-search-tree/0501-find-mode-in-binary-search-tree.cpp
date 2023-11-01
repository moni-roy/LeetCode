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
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        int max_streak = 0, current_streak = 0, current_num = 0;
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                TreeNode* node = curr->left;
                while (node->right != nullptr)  node = node->right;
                node->right = curr;
                TreeNode* left = curr->left;
                curr->left = nullptr;
                curr = left;
            } else {
                int num = curr->val;
                if (num == current_num) current_streak ++;
                else {
                    current_streak = 1;
                    current_num = num;
                }
                if (current_streak > max_streak) {
                    max_streak = current_streak;
                    result = {};
                } 
                if(current_streak == max_streak) {
                    result.push_back(num);
                }
                curr = curr->right;
            }
        }
        return result;
    }
};