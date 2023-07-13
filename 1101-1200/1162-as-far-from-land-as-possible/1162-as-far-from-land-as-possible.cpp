class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = -1;
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    dp[i][j] = 0;
                }
            }
        }
        if(q.empty()) return -1;
        
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = p.first + dx[i], ny = p.second + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == -1) continue;
                if (dp[nx][ny] == -1) {
                    dp[nx][ny] = dp[p.first][p.second] + 1;
                    q.push({nx, ny});
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0 && dp[i][j] != -1) {
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
};