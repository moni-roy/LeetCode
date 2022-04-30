class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++) {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        vector<double> res;
        for (int i = 0; i < queries.size(); i++) {
            // visited
            unordered_set<string> visited;
            if (graph.count(queries[i][0]) && graph.count(queries[i][1])) {
                res.push_back(dfs(graph, queries[i][0], queries[i][1], visited));
            } else {
                res.push_back(-1.0);
            }
        }
        return res;
    }
private:
    double dfs(unordered_map<string, unordered_map<string, double>>& graph, string start, string end, unordered_set<string>& visited) {
        if (start == end) {
            return 1.0;
        }
        if (visited.count(start)) {
            return -1.0;
        }
        visited.insert(start);
        for (auto& pair : graph[start]) {
            if (pair.second != 0.0) {
                double res = dfs(graph, pair.first, end, visited);
                if (res != -1.0) {
                    return res * pair.second;
                }
            }
        }
        return -1.0;
    }
};