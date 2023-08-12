class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return dfs(obstacleGrid, dp, 0, 0);
    }
private:
    int dfs(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int x, int y) {
        if (x < 0 || x >= obstacleGrid.size() || y < 0 || y >= obstacleGrid[0].size()) return 0;
        if (x == obstacleGrid.size()-1 && y == obstacleGrid[0].size()-1) return !obstacleGrid[x][y];
        if (dp[x][y]!= -1) return dp[x][y];
        if (obstacleGrid[x][y] == 1) return dp[x][y] = 0;
        return dp[x][y] = dfs(obstacleGrid, dp, x, y + 1) + dfs(obstacleGrid, dp, x + 1, y);
    }
};