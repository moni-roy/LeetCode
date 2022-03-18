class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        dfs(0, graph, paths, {});
        return paths;
    }
    void dfs(int u, vector<vector<int>>& graph, vector<vector<int>>& paths, vector<int> path) {
        path.push_back(u);
        if(u == graph.size()-1) {
            paths.push_back(path);
        }
        for(auto v: graph[u]) {
            dfs(v, graph, paths, path);
        }
        path.pop_back();
    }
};