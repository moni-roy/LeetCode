class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int vs[55][55];
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int> >, vector<pair<int,pair<int,int> > >, greater<pair<int, pair<int,int> > > > pq;
        pq.push({grid[0][0], {0, 0}});
        int ans = 0, n = grid.size();
        while(!pq.empty()) {
            pair<int, pair<int,int>> p = pq.top();
            pq.pop();
            ans = ans < p.first ? p.first : ans;
            if(p.second.first == n - 1 && p.second.second == n - 1) return ans;
            for(int i = 0; i<4;i++) {
                int x = dx[i] + p.second.first;
                int y = dy[i] + p.second.second;
                if(x >= 0 && x < n && y >= 0 && y < n && !vs[x][y]) {
                    vs[x][y] = 1;
                    pq.push({grid[x][y], {x, y}});
                }
            }
        }
        return ans;
    }
};