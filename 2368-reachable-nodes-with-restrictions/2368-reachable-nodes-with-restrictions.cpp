class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> graph(n, vector<int>());
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> visited(n, 0);
        for (auto r : restricted) {
            visited[r] = 1;
        }
        int res = 0;
        dfs(graph, visited, 0, res);
        return res;
    }
private:
    void dfs(vector<vector<int>>& graph, vector<int>& visited, int cur, int& res) {
        if (visited[cur]) {
            return;
        }
        visited[cur] = 1;
        res++;
        for (auto next : graph[cur]) {
            dfs(graph, visited, next, res);
        }
    }
};