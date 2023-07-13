class Solution {
public:
    struct Node {
        bool isEnd = false;
        vector<Node*> next {vector<Node *>(26, NULL)};
    };
    
    void insert(string &s, Node *root) {
        Node *node = root;
        for(auto c: s){
            int t = c-'a';
            if(!node->next[t]) {
                node->next[t] = new Node();
            }
            node = node->next[t];
        }
        node->isEnd = true;
    }
    
    vector<string> getWords(string &s, Node *root) {
        Node *node = root;
        vector<string> ret;
        
        for(auto c: s) {
            int t = c-'a';
            if(!node->next[t]){
                return ret;
            }
            node=node->next[t];
        }
        dfs(node, s, ret);
        return ret;
    }
    
    void dfs(Node *node, string &s, vector<string> &ret) {
        if(ret.size()==3) return;
        if(node->isEnd) ret.push_back(s);
        for(int t = 0; t<26;t++) {
            char c = t + 'a';
            if(node->next[t]) {
                s += c;
                dfs(node->next[t], s, ret);
                s.pop_back();
            }
        }
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Node *root = new Node();
        vector<vector<string>> ret;
        
        for(auto s: products) {
            insert(s, root);
        }
        string s;
        for(auto c: searchWord){
            s += c;
            ret.push_back(getWords(s, root));
        }
        return ret;
    }
};