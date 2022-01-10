class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(matrix, dp, i, j));
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j]) return dp[i][j];
        int m = matrix.size(), n = matrix[0].size();
        int ans = 1;
        for (int d = 0; d < 4; ++d) {
            int x = i + dx[d], y = j + dy[d];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
            ans = max(ans, 1 + dfs(matrix, dp, x, y));
        }
        dp[i][j] = ans;
        return ans;
    }
};