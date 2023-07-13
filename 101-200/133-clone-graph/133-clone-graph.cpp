/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        unordered_map<Node*, Node*> exists;
        return dfs(node, exists);
    }
    Node* dfs(Node* node, unordered_map<Node*, Node*>& exists) {
        if(exists.find(node) != exists.end()) return exists[node];
        Node* newNode = new Node(node->val);
        exists[node] = newNode;
        for(Node* neighbor : node->neighbors) {
            newNode->neighbors.push_back(dfs(neighbor, exists));
        }
        return newNode;
    }
};