
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // using spanning tree to find the minimum cost
        int n = points.size();
        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // manhattan distance
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({d, {i, j}});
            }
        }
        sort(edges.begin(), edges.end());
        vector<int> parent(n, -1);
        for(int i = 0; i < n; i++) parent[i] = i;
        int cost = 0;
        for (auto& e : edges) {
            int u = e.second.first, v = e.second.second;
            if (find(u, parent) != find(v, parent)) {
                cost += e.first;
                parent[find(u, parent)] = find(v, parent);
            }
        }
        return cost;
    }
private:
    int find(int x, vector<int>& parent) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }
};