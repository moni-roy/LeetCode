class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        vector<int> visited(n, 0);
        return dfs(graph, visited, source, destination);

    }
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int source, int destination) {
        if (visited[source] != 0) {
            return visited[source] == 2;
        }
        
        if (graph[source].empty()) {
            return source == destination;
        }

        visited[source] = 1;
        for (auto& next : graph[source]) {
            if (!dfs(graph, visited, next, destination)) {
                return false;
            }
        }
        visited[source] = 2;
        return true;
    }
};