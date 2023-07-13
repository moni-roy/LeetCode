class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> m;
        for (auto &w : wordDict) {
            m[w] = true;
        }
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && m[s.substr(j, i - j)]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};