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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        // return usingInorder(root1, root2);
        return usingSort(root1, root2);
    }
private:
    vector<int> usingInorder(TreeNode* root1, TreeNode* root2) {
        vector<int> inorderRoot1;
        inorder(root1, inorderRoot1);
        vector<int> inorderRoot2;
        inorder(root2, inorderRoot2);
        int len1 = inorderRoot1.size(), len2 = inorderRoot2.size();
        vector<int> ans;
        int i = 0, j = 0;
        while(i < len1 && j < len2) {
            if(inorderRoot1[i] <= inorderRoot2[j]) {
                ans.push_back(inorderRoot1[i++]);
            }
            else {
                ans.push_back(inorderRoot2[j++]);
            }
        }
        while(i<len1) ans.push_back(inorderRoot1[i++]);
        while(j<len2) ans.push_back(inorderRoot2[j++]);
        return ans;
    }
    
    void inorder(TreeNode *root, vector<int> &values) {
        if(!root) return;
        inorder(root->left, values);
        values.push_back(root->val);
        inorder(root->right, values);
    }

    vector<int> usingSort(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        inorder(root1, ans);
        inorder(root2, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};