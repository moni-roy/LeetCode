class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, int>>> graph(n), rev_graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            rev_graph[edge[1]].push_back({edge[0], edge[2]});
        }
        auto costFromSrc1 = dijkstra(graph, src1), costFromSrc2 = dijkstra(graph, src2), costToDest = dijkstra(rev_graph, dest);
        long long ans = LLONG_MAX;
        for (int i = 0; i < n; ++i) {
            if (costFromSrc1[i] == LLONG_MAX || costFromSrc2[i] == LLONG_MAX || costToDest[i] == LLONG_MAX) continue;
            ans = min(ans, costFromSrc1[i] + costFromSrc2[i] + costToDest[i]);
        }
        return ans == LLONG_MAX ? -1 : ans;
    }
private:
    vector<long long> dijkstra(vector<vector<pair<int, int>>>& graph, int src) {
        vector<long long> dist(graph.size(), LLONG_MAX);
        dist[src] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if (dist[cur.second] < cur.first) continue;
            for (auto& edge : graph[cur.second]) {
                if (dist[edge.first] > dist[cur.second] + edge.second) {
                    dist[edge.first] = dist[cur.second] + edge.second;
                    pq.push({dist[edge.first], edge.first});
                }
            }
        }
        return dist;
    }
};