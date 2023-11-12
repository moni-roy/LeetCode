class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        unordered_map<int, vector<int> > graph;
        for (int route = 0; route < routes.size(); route++) {
            for (auto stop: routes[route]) {
                graph[stop].push_back(route);
            }
        }
        // bfs
        queue<int> q;
        unordered_set<int> vis;
        for (auto route: graph[source]) {
            q.push(route);
            vis.insert(route);
        }
        int count = 1;
        while(!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int route = q.front();
                q.pop();
                for (auto u: routes[route]) {
                    if (u == target) return count;
                    for (auto v: graph[u]) {
                        if (vis.find(v) != vis.end()) continue;
                        vis.insert(v);
                        q.push(v);
                    }
                }
            }
            count++;
        }
        return -1;
    }
};