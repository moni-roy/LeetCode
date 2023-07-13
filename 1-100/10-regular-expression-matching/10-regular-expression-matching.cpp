class Solution {
public:
    bool isMatch(string s, string p) {
		vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
		return recur(0, 0, s, p, dp);
    }
private:
	bool recur(int i, int j, string& s, string& p, vector<vector<bool>>& dp) {
		if (dp[i][j]) return dp[i][j];
		if (j == p.size()) return i == s.size();

		bool first_match = i < s.size() && (s[i] == p[j] || p[j] == '.');
		if (j + 1 < p.size() && p[j+1] == '*') {
			dp[i][j] = recur(i, j+2, s, p, dp) || first_match && recur(i+1, j, s, p, dp);
		} else {
			dp[i][j] = first_match && recur(i+1, j+1, s, p, dp);
		}
		return dp[i][j];
	}
    
    bool isMatch_DP_BOTTOM(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < n; ++i) {
            if (p[i] == '*') {
                dp[0][i + 1] = dp[0][i - 1];
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (p[j] == '*') {
                    dp[i + 1][j + 1] = dp[i + 1][j - 1] || (s[i] == p[j - 1] || p[j - 1] == '.') && dp[i][j+1];
                } else {
                    dp[i + 1][j + 1] = dp[i][j] && (s[i] == p[j] || p[j] == '.');
                }
            }
        }
        return dp[m][n];
    }
};
