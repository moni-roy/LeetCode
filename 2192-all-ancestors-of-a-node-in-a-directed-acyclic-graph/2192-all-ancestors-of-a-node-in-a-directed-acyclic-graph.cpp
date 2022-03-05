class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n, vector<int>());
        vector<vector<int>> graph(n, vector<int>());
        for (auto& edge : edges) {
            graph[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            dfs(i, graph, res, i, visited);
        }
        for (int i = 0; i < n; ++i) {
            sort(res[i].begin(), res[i].end());
        }
        return res;
    }
private:
    void dfs(int node, vector<vector<int>>& graph, vector<vector<int>>& res, int parent, vector<bool>& visited) {
        visited[node] = true;
        if(parent != node) res[parent].push_back(node);
        for (auto& child : graph[node]) {
            if (!visited[child]) {
                dfs(child, graph, res, parent, visited);
            }
        }
    }
};