class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    bool isClosed = true;
                    dfs(grid, i, j, m, n, isClosed);
                    if (isClosed) ++res;
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, bool& isClosed) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1) return;
        if (i == 0 || i == m - 1 || j == 0 || j == n - 1) isClosed = false;
        grid[i][j] = 1;
        dfs(grid, i - 1, j, m, n, isClosed);
        dfs(grid, i + 1, j, m, n, isClosed);
        dfs(grid, i, j - 1, m, n, isClosed);
        dfs(grid, i, j + 1, m, n, isClosed);
    }
};