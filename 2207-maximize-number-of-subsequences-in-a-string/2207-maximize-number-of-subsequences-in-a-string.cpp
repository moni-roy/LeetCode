class Solution {
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.size();
        long long ans = 0, first = 0, last = 0;
        for (auto c : text) {
            if(pattern[1] == c) ans += first;
            first += (pattern[0] == c);
            last += (pattern[1] == c);
        }
        return ans + max(first, last);
    }
private:
    long long usingExtraSpace(string text, string pattern) {
        int n = text.size(), m = pattern.size();
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