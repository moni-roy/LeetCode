class Solution {
public:
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
        int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};
        vector<vector<int> > vs (101, vector<int>(101, 0));
        queue<int> q;
        if(!grid[0][0]) {
            q.push(0);
            q.push(0);
            vs[0][0] = 1;
        }
        
        while(!q.empty()) {
            int u = q.front(); q.pop();
            int v = q.front(); q.pop();
            
            if(u == grid.size()-1 && v == grid[0].size()-1) return vs[u][v];
            
            for(int i = 0; i < 8; i++) {
                int x = u + dx[i];
                int y = v + dy[i];
                
                if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && !vs[x][y] && !grid[x][y])
                {
                    q.push(x);
                    q.push(y);
                    vs[x][y] = vs[u][v] + 1;
                }
            }
        }
        return -1;
    }
};