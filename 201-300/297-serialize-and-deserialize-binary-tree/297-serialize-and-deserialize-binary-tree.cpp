/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "# ";
        stringstream ss;
        ss << root->val << " ";
        ss << serialize(root->left);
        ss << serialize(root->right);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> que;
        stringstream ss(data);
        string val;
        while(ss >> val) {
            que.push(val);
        }
        return deserialize(que);
    }
private:
    TreeNode *deserialize(queue<string> &que) {
        string val = que.front();
        que.pop();
        if(val == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(que);
        root->right = deserialize(que);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));