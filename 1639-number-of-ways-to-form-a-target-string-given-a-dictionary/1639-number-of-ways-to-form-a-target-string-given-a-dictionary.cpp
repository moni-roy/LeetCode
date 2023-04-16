class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = words.size(), m = words[0].size(), t = target.size();
        vector<vector<int>> cnt(m, vector<int>(26));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ++cnt[j][words[i][j] - 'a'];
            }
        }
        vector<vector<int>> dp(t + 1, vector<int>(m + 1, -1));
        return dfs(t, m, cnt, target, dp);
    }
private:
    long long dfs(int t, int m, vector<vector<int>>& cnt, string& target, vector<vector<int>>& dp) {
        if (m == 0) return t == 0;
        if (dp[t][m] != -1) return dp[t][m];
        long long res = 0;
        if (t > 0) {
            res = dfs(t - 1, m - 1, cnt, target, dp) * cnt[m - 1][target[t - 1] - 'a'];
            res %= 1000000007;
        }
        res += dfs(t, m - 1, cnt, target, dp);
        res %= 1000000007;
        return dp[t][m] = res;
    }
};