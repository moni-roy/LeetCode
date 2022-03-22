class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int res = 0;
        vector<vector<bool>> graph(n, vector<bool>(n, false));
        vector<int> degree(n, 0);
        for (auto& road : roads) {
            graph[road[0]][road[1]] = true;
            graph[road[1]][road[0]] = true;
            degree[road[0]]++;
            degree[road[1]]++;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res = max(res, degree[i] + degree[j] - (graph[i][j] ? 1 : 0));
            }
        }
        return res;
    }
};