class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        return getAncestorsGraph(n, edges);
    }
private:
    vector<vector<int>> getAncestorsGraph(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        vector<vector<int>> ancestors(n);
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            getAncestors(i, i, graph, ancestors, visited);
        }
        return ancestors;
    }

    void getAncestors(int node, int parent, vector<vector<int>>& graph, vector<vector<int>>& ancestors, vector<bool>& visited) {
        visited[node] = true;
        for (int child : graph[node]) {
            if (!visited[child]) {
                ancestors[child].push_back(parent);
                getAncestors(child, parent, graph, ancestors, visited);
            }
        }
    }

    // using reverse graph
    vector<vector<int>> getAncestorsReverseGraph(int n, vector<vector<int>>& edges) {
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

    void dfs(int node, vector<vector<int>>& graph, vector<vector<int>>& res, int parent, vector<bool>& visited) {
        visited[node] = true;
        for (auto& child : graph[node]) {
            if (!visited[child]) {
                res[parent].push_back(child);
                dfs(child, graph, res, parent, visited);
            }
        }
    }
};