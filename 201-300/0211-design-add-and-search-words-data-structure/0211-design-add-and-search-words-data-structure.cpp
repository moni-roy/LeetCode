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

class WordDictionary {
private:
    TrieNode* root = new TrieNode();
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
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
        return usingRecursion(root, word, 0);
    }

    bool usingRecursion(TrieNode* root, string word, int index) {
        if(index == word.size()) {
            return root->isEnd;
        }
        if(word[index] == '.') {
            for(int i = 0; i < 26; i++) {
                if(root->children[i] != NULL && usingRecursion(root->children[i], word, index+1)) {
                    return true;
                }
            }
        } else {
            if(root->children[word[index]-'a'] != NULL && usingRecursion(root->children[word[index]-'a'], word, index+1)) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */