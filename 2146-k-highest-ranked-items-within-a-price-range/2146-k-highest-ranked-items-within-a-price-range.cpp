class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        auto cmp = [&](const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
            return (a.first < b.first) || (a.first == b.first && grid[a.second.first][a.second.second] < grid[b.second.first][b.second.second]) || (a.first == b.first && grid[a.second.first][a.second.second] == grid[b.second.first][b.second.second] && a.second.first < b.second.first) || (a.first == b.first && grid[a.second.first][a.second.second] == grid[b.second.first][b.second.second] && a.second.first == b.second.first && a.second.second < b.second.second);
        };

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(cmp)> pq(cmp);
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), -1));
        queue<pair<int, int>> q;
        dist[start[0]][start[1]] = 0;
        q.push(make_pair(start[0], start[1]));
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            if(grid[cur.first][cur.second]>= pricing[0] && grid[cur.first][cur.second] <= pricing[1]) {
                pq.push({dist[cur.first][cur.second], cur});
                if(pq.size() > k) {
                    pq.pop();
                }
            }
            for(int i = 0; i < 4; i++) {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] > 0 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[cur.first][cur.second] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()) {
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};