struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(auto c: word) {
            if(cur->children[c-'a'] == NULL) {
                cur->children[c-'a'] = new TrieNode();
            }
            cur = cur->children[c-'a'];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode *cur = root;
        for(auto c: word) {
            if(cur->children[c-'a'] == NULL) {
                return false;
            }
            cur = cur->children[c-'a'];
        }
        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(auto c: prefix) {
            if(cur->children[c-'a'] == NULL) {
                return false;
            }
            cur = cur->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */