class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.size();
        vector<long long> firstCharCount(n + 1, 0), secondCharCount(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            firstCharCount[i + 1] = firstCharCount[i] + (text[i] == pattern[0]);
            secondCharCount[i + 1] = secondCharCount[i] + (text[i] == pattern[1]);
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            if (text[i] == pattern[1]) {
                ans += firstCharCount[i];
            }
        }
        long long mx = max(firstCharCount[n], secondCharCount[n]);
        return ans + mx;
    }
};