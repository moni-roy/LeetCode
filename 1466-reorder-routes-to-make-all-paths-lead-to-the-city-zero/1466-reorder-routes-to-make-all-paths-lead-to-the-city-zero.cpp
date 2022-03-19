class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& c : connections) {
            graph[c[0]].push_back({c[1], 1});
            graph[c[1]].push_back({c[0], 0});
        }
        vector<int> visited(n, 0);
        int ans = 0;
        dfs(graph, 0, visited, ans);
        return ans;
    }
private:
    void dfs(vector<vector<pair<int, int>>>& graph, int node, vector<int>& visited, int& ans) {
        visited[node] = 1;
        for (auto& n : graph[node]) {
            if (visited[n.first]) continue;
            ans += n.second;
            dfs(graph, n.first, visited, ans);
        }
    }
};