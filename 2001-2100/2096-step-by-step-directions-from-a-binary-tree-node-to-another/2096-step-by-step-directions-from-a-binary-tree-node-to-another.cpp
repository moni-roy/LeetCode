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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = findLCA(root, startValue, destValue);
        if (lca == NULL) return "";
        string lcaToStart = "";
        getPath(lca, startValue, lcaToStart);
        string lcaToDest = "";
        getPath(lca, destValue, lcaToDest);
        reverse(lcaToDest.begin(), lcaToDest.end());
        for(auto &c: lcaToStart)  c = 'U';
        return lcaToStart + lcaToDest;
    }

private:
    TreeNode *findLCA(TreeNode *root, int startValue, int destValue) {
        if (!root || root->val == startValue || root->val == destValue) {
            return root;
        }

        TreeNode *left = findLCA(root->left, startValue, destValue);
        TreeNode *right = findLCA(root->right, startValue, destValue);

        return !left ? right : (!right ? left : root);
    }

    bool getPath(TreeNode *root, int value, string &path) {
        if (root->val == value) {
            return true;
        }
        if(root->left && getPath(root->left, value, path)) {
            path += 'L';
            return true;
        }
        if(root->right && getPath(root->right, value, path)) {
            path += 'R';
            return true;
        }
        return !path.empty();
    }
};