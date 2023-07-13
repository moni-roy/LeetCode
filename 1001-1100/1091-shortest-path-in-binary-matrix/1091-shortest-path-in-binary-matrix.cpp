class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>> visited(n, vector<int>(n, 0));
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 1;
        int step = 0;
        // 8 directions
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        // BFS
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (x == n-1 && y == n-1) return step + 1;
                for (auto dir : dirs) {
                    int new_x = x + dir.first;
                    int new_y = y + dir.second;
                    if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n || grid[new_x][new_y] == 1 || visited[new_x][new_y] == 1) continue;
                    q.push({new_x, new_y});
                    visited[new_x][new_y] = 1;
                }
            }
            step++;
        }
        return -1;
    }
};