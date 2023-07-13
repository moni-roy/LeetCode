class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for (auto& redEdge : redEdges) {
            graph[redEdge[0]].push_back({redEdge[1], 0});
        }
        for (auto& blueEdge : blueEdges) {
            graph[blueEdge[0]].push_back({blueEdge[1], 1});
        }
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({0, 1});

        vector<vector<int>> dist(n, vector<int>(2, -1));
        dist[0] = {0, 0};

        while (!q.empty()) {
            auto [node, color] = q.front();
            q.pop();
            for (auto& [neighbor, neighborColor] : graph[node]) {
                if(color == neighborColor || dist[neighbor][neighborColor] != -1) continue;
                dist[neighbor][neighborColor] = dist[node][color] + 1;
                q.push({neighbor, neighborColor});
            }
        }
        vector<int> res;
        for(auto d: dist) {
            sort(d.begin(), d.end());
            res.push_back(d[0] != -1 ? d[0] : d[1]);
        }
        return res;
    }
};