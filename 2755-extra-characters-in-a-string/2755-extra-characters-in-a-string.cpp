class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;
};
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        auto root = buildTrie(dictionary);
        int len = s.length();
        unordered_map<int, int> memo;

        function<int(int)> dp = [&](int pos) {
            if (pos == len) return 0;
            if (memo.find(pos)!= memo.end()) return memo[pos];
            int res = dp(pos + 1) + 1;
            TrieNode* node = root;
            for (int idx = pos; idx < len; idx++) {
                char c = s[idx];
                if (node->children.find(c) == node->children.end()) break;
                node = node->children[c];
                if (node->isWord) res = min(res, dp(idx + 1));
            }
            return memo[pos] = res;
        };
        return dp(0);
    }

    TrieNode* buildTrie(vector<string>& dictionary) {
        auto root = new TrieNode();
        for (auto& word : dictionary) {
            auto node = root;
            for (auto c : word) {
                if (node->children.find(c) == node->children.end()) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->isWord = true;
        }
        return root;
    }
};
