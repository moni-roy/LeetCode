class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        // dirs 
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        // queue
        queue<vector<int>> q;
        q.push(entrance);
        // visited
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[entrance[0]][entrance[1]] = true;
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            res++;
            for (int i = 0; i < size; i++) {
                vector<int> cur = q.front();
                q.pop();
                for (auto dir : dirs) {
                    int x = cur[0] + dir[0];
                    int y = cur[1] + dir[1];
                    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || maze[x][y] == '+') continue;
                    if(x == m - 1 || y == n - 1 || x == 0 || y == 0) return res;
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        return -1;
    }
};