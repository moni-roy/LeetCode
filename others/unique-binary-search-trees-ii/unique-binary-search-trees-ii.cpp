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
class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        return getTrees(1, n);
    }

    vector<TreeNode *> getTrees(int s, int e)
    {
        vector<TreeNode *> ret;
        if (s > e)
        {
            ret.push_back(NULL);
            return ret;
        }
        if (s == e)
        {
            ret.push_back(new TreeNode(s));
            return ret;
        }
        vector<TreeNode*> left, right;
        
        for(int i = s; i<=e; i++) {
            left = getTrees(s, i-1);
            right = getTrees(i+1, e);
            for(auto l: left) {
                for(auto r: right) {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};