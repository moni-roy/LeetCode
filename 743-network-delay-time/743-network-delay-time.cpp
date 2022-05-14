class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // construct graph
        vector<vector<pair<int, int>>> graph(n);
        for (auto& time : times) {
            graph[time[0] - 1].push_back({time[1] - 1, time[2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[k-1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k-1});
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            for (auto& next : graph[cur.second]) {
                if (dist[next.first] > cur.first + next.second) {
                    dist[next.first] = cur.first + next.second;
                    pq.push({dist[next.first], next.first});
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (dist[i] == INT_MAX) return -1;
            res = max(res, dist[i]);
        }
        return res;
    }
};