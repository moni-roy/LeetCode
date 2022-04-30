class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        unordered_map<string, int> freq;
        for (auto& word : words) freq[word]++;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            string prefix = s.substr(0, i + 1);
            if (freq.count(prefix)) count += freq[prefix];
        }
        return count;
    }
};