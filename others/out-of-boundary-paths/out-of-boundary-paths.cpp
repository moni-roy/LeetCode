class Solution {
public:
    int md = 1e9+7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return dfs(startRow, startColumn, m, n, maxMove, dp);
    }
    
    int dfs(int x, int y, int m, int n, int k, vector<vector<vector<int>>> &dp) {
        if((x == m) || (y == n) || (x < 0) || (y < 0)) {
          return 1;  
        } 
        if( k == 0) return 0;
        if(dp[x][y][k] != -1) return dp[x][y][k];
        
        int ret = (dfs(x - 1, y, m, n, k - 1, dp) + dfs(x + 1, y, m, n, k - 1, dp)) % md +
                  (dfs(x, y - 1, m, n, k - 1, dp) + dfs(x, y + 1, m, n, k - 1, dp)) % md;
        
        return dp[x][y][k] = ret % md;
    }
};