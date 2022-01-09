class Solution {
public:
    int dir[8][2] = {{ -1, 0} , { -1, -1}, { -1, 1}, {0, -1}, {0, 1 } , {1, -1}, {1, 0 }, {1, 1 }};

    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> preSum(rows + 1, vector<int>(cols + 1, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                preSum[i + 1][j + 1] = preSum[i + 1][j] + preSum[i][j + 1] - preSum[i][j] + grid[i][j];
            }
        }
        vector<vector<int>> dp(rows + 2, vector<int>(cols + 2, 0));
        for (int i = stampHeight; i <= rows; i++) {
            for (int j = stampWidth; j <= cols; j++) {
                int l = max(0, i - stampHeight);
                int r = max(0, j - stampWidth);
                int sum = preSum[i][j] - preSum[i][r] - preSum[l][j] + preSum[l][r];
                if(sum == 0) {
                    dfs(i, j, i, j, l + 1, r + 1, dp);
                }
            }
        }
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if( grid[i-1][j-1] == 0 && dp[i][j] == 0) {
                    return false;
                }
            }
        }
        return true;
    }
    void dfs(int i, int j, int h, int w, int l, int r, vector<vector<int>>& dp) {
        if(i <= h && i >= l && j <= w && j >= r) {
            if(!dp[i][j]) {
                dp[i][j] = 1;
                for(int k = 0; k < 8; k++) {
                    dfs(i + dir[k][0], j + dir[k][1], h, w, l, r, dp);
                }
            }
        }
    }
};