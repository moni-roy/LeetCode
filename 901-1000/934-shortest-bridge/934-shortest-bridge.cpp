class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();


        // dfs to set all 1s to 2s and insert all 1s into queue
        queue<pair<int, int>> q;

        // find the first island
        for (int i = 0; i < n; ++i) {
            int j = 0;
            for (; j < n; ++j) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, q);
                    break;
                }
            }
            if (j < n) break;
        }
        // dirs
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        // bfs
        int step = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();
                for (auto dir : dirs) {
                    int x = cur.first + dir[0];
                    int y = cur.second + dir[1];
                    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 2) continue;
                    if (grid[x][y] == 1) return step;
                    grid[x][y] = 2;
                    q.push({x, y});
                }
            }
            ++step;
        }
        return step;
    }
private:
    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) return;
        grid[i][j] = 2;
        q.push({i, j});
        dfs(grid, i + 1, j, q);
        dfs(grid, i - 1, j, q);
        dfs(grid, i, j + 1, q);
        dfs(grid, i, j - 1, q);
    }
};