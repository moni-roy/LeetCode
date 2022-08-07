class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int>dp (26, 0);
        int ans = 0;
        for (auto c : s) {
            int idx = c - 'a';
            for (int i = max(0, idx - k); i <= min(25, idx + k); i++) {
                dp[idx] = max(dp[idx], dp[i]);
            }
            ans = max(ans, ++dp[idx]);
        }
        return ans;
    }
};