struct TrieNode {
    TrieNode* children[26];
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        // return usingHashSet(nums);
        return usingTrie(nums);
    }
private:
    int usingHashSet(vector<int> &nums) {
        int maxPrefix = 0, mask = 0;
        for (int i = 31; i >= 0; --i) {
            unordered_set<int> prefixes;
            mask = mask | (1 << i);
            for (int num : nums) {
                prefixes.insert(num & mask);
            }
            int currPrefix = maxPrefix | (1 << i);
            for (int prefix : prefixes) {
                if (prefixes.count(currPrefix ^ prefix)) {
                    maxPrefix = currPrefix;
                    break;
                }
            }
        }
        return maxPrefix;
    }
    int usingTrie(vector<int> &nums) {
        TrieNode *root = new TrieNode();
        for (int num : nums) {
            TrieNode *curr = root;
            for (int i = 31; i >= 0; --i) {
                int bit = (num >> i) & 1;
                if (!curr->children[bit]) {
                    curr->children[bit] = new TrieNode();
                }
                curr = curr->children[bit];
            }
        }
        int maxPrefix = 0;
        for (int num : nums) {
            TrieNode *curr = root;
            int currPrefix = 0;
            for (int i = 31; i >= 0; --i) {
                int bit = (num >> i) & 1;
                if (curr->children[1 - bit]) {
                    currPrefix = currPrefix | (1 << i);
                    curr = curr->children[1 - bit];
                } else {
                    curr = curr->children[bit];
                }
            }
            maxPrefix = max(maxPrefix, currPrefix);
        }
        return maxPrefix;
    }
};