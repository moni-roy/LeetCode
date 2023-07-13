/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        int mx = 0;
        dfs(root, mx, 1);
        return mx;
    }
private:
    void dfs(Node* root, int& mx, int depth) {
        if (!root) return;
        mx = max(mx, depth);
        for (auto& c : root->children) {
            dfs(c, mx, depth + 1);
        }
    }
};