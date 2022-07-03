class Solution {
public:
    int characterReplacement(string s, int k) {
        // sliding window
        int n = s.size();
        int max_count = 0;
        int max_len = 0;
        int start = 0;
        int end = 0;
        vector<int> count(26, 0);
        while (end < n) {
            count[s[end] - 'A']++;
            max_count = max(max_count, count[s[end] - 'A']);
            end++;
            while (end - start > k + max_count) {
                count[s[start] - 'A']--;
                start++;
            }
            max_len = max(max_len, end - start);
        }
        return max_len;
    }
};