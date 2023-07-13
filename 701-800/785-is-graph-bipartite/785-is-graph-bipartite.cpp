class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1 && !dfs(graph, color, i, 0)) {
                return false;
            }
        }
        return true;
    }
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int cur, int c) {
        if (color[cur] != -1) {
            return color[cur] == c;
        }
        color[cur] = c;
        for (int next : graph[cur]) {
            if (!dfs(graph, color, next, c ^ 1)) {
                return false;
            }
        }
        return true;
    }
};