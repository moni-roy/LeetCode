class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int res = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < walls.size(); i++) {
            int x = walls[i][0];
            int y = walls[i][1];
            visited[x][y] = 2;
        }
        for(int i = 0; i < guards.size(); i++) {
            int x = guards[i][0];
            int y = guards[i][1];
            visited[x][y] = 2;
        }
        for(int i = 0; i < guards.size(); i++) {
            int x = guards[i][0];
            int y = guards[i][1];
            // up
            for (int j = y - 1; j >= 0; j--) {
                if (visited[x][j] == 2) break;
                visited[x][j] = 1;
            }
            // down
            for (int j = y + 1; j < n; j++) {
                if (visited[x][j] == 2) break;
                visited[x][j] = 1;
            }
            // left
            for (int j = x - 1; j >= 0; j--) {
                if (visited[j][y] == 2) break;
                visited[j][y] = 1;
            }
            // right
            for (int j = x + 1; j < m; j++) {
                if (visited[j][y] == 2) break;
                visited[j][y] = 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visited[i][j] == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};