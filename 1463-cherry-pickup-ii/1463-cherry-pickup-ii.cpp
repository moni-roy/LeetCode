class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return dfs(grid, 0, 0, grid[0].size()-1, dp);
    }

    int dfs(vector<vector<int>> &grid, int r1, int c1, int c2, vector<vector<vector<int>>> &dp) {
        if (r1 == grid.size() || c1 < 0 || c2 < 0 || c1 >= grid[0].size() || c2 >= grid[0].size()) return 0;
        if (dp[r1][c1][c2] != -1) return dp[r1][c1][c2];
        int ans = grid[r1][c1];
        if (c1 != c2) ans += grid[r1][c2];
        if (r1 == grid.size()-1) return dp[r1][c1][c2] = ans;
        int mx = 0;
        for(int nc1 = c1 - 1; nc1 <= c1 + 1; nc1++) {
            for(int nc2 = c2 - 1; nc2 <= c2 + 1; nc2++) {
                mx = max(mx, dfs(grid, r1+1, nc1, nc2, dp));
            }
        }
        return dp[r1][c1][c2] = ans + mx;
    }
};