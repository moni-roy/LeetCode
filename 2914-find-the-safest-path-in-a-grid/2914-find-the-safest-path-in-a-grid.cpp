class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // bfs
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
        while (!q.empty()) {
            auto [u, v] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int x = u + dx[i], y = v + dy[i];
                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0) {
                    grid[x][y] = grid[u][v] + 1;
                    q.push({x, y});
                }
            }
        }
        int ans = 0;
        // dijkstra
        priority_queue<pair<int, pair<int, int>> > pq;
        pq.push({grid[0][0], {0, 0}});
        while (!pq.empty()) {
            auto v = pq.top(); pq.pop();
            if (v.second.first == m - 1 && v.second.second == n - 1) {
                ans = v.first;
                break;
            }
            int x = v.second.first, y = v.second.second;
            for (int i = 0; i < 4; i++) {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx >= 0 && xx < m && yy >= 0 && yy < n && grid[xx][yy] != -1) {
                    pq.push({min(v.first, grid[xx][yy]), {xx, yy}});
                    grid[xx][yy] = -1;
                }
            }
        }
        return ans - 1;
    }
};