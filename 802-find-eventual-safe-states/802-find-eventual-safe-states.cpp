class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        vector<int> color(n, 0);  // 0: white, 1: gray, 2: black
        for (int i = 0; i < n; ++i) {
            if (dfs(graph, i, color)) res.push_back(i);
        }
        return res;
    }
private:
    bool dfs(vector<vector<int>>& graph, int i, vector<int>& color) {
        if (color[i] == 1) return false;
        if (color[i] == 2) return true;
        color[i] = 1;
        for (int j : graph[i]) {
            if (!dfs(graph, j, color)) return false;
        }
        color[i] = 2;
        return true;
    }
};