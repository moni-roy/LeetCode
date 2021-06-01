class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int vs[55][55] = {0};
    int ret;
    
    void dfs(int x, int y, vector<vector<int>> &grid){
        ret += 1;
        vs[x][y] = 1;
        
        for(int i = 0; i<4; i++) {
            int xx = dx[i] + x;
            int yy = dy[i] + y;
            if(0 <= xx && xx < grid.size() && 0 <= yy && yy < grid[0].size()) {
                if(vs[xx][yy] == 0 && grid[xx][yy] == 1) {
                    dfs(xx, yy, grid);
                }
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int ans= 0;
        for(int i = 0; i<grid.size();i++) {
            for(int j = 0; j< grid[0].size(); j++) {
                if(grid[i][j] && vs[i][j] == 0) {
                    ret = 0;
                    dfs(i,j, grid);
                    ans = max(ans, ret);
                }
            }
        }
        return ans;
    }
};