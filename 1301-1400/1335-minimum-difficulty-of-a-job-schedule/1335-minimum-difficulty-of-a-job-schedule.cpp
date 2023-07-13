class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;
        vector<vector<int>> dp(n, vector<int>(d, -1));
        return dfs(jobDifficulty, 0, d, dp);
    }
private:
    int dfs(vector<int>& jobDifficulty, int start, int d, vector<vector<int>>& dp) {
        if (d == 1) {
            return *max_element(jobDifficulty.begin() + start, jobDifficulty.end());
        }
        if (dp[start][d - 1] != -1) {
            return dp[start][d - 1];
        }
        int res = INT_MAX;
        int maxDiff = 0;
        for (int cur = start; cur < jobDifficulty.size() - d + 1; ++cur) {
            maxDiff = max(maxDiff, jobDifficulty[cur]);
            res = min(res, maxDiff + dfs(jobDifficulty, cur + 1, d - 1, dp));
        }
        return dp[start][d - 1] = res;
    }
};