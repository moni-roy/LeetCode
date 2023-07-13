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
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int> > ret;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> cl;
            for (int i = 0; i<sz; i++) {
                Node *t = q.front(); q.pop();
                cl.push_back(t->val);
                for (auto c: t->children) {
                    q.push(c);
                }
            }
            ret.push_back(cl);
        }
        return ret;
    }
};