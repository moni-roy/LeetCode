class Solution {
public:
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<int> > dir = {{0, 1},{0, -1},{1, 0},{-1, 0}};
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<vector<int> > q;
        vector<vector<vector<int> > > vs(n+1, vector<vector<int>>(m+1, vector<int>(k+1, 0)));
        
        q.push({0, 0, k, 0});
        vs[0][0][k] = 1;
        
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            int x = p[0], y = p[1], r = p[2], s = p[3];
            
            if(x == n-1 && y== m-1) return s;
            
            for(auto d: dir){
                int xx = x + d[0];
                int yy = y + d[1];
                
                if(xx >= 0 && xx <n && yy>=0 && yy<m){
                    if(vs[xx][yy][r] == 0){
                        vs[xx][yy][r] = 1;
                        
                        if(grid[xx][yy] && r) {
                            q.push({xx, yy, r-1, s+1});
                        }
                        else if(grid[xx][yy]==0) {
                            q.push({xx, yy, r, s+1});
                        }
                    }
                }
            }
        }
        return -1;
        
    }
};