class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = s.size(), res = 0;
        vector<vector<int>> graph(n);
        for(int i = 1; i < parent.size(); ++i) {
            graph[parent[i]].push_back(i);
        }
        dfs(graph, 0, s, res);
        return res;
    }
private:
    int dfs(vector<vector<int>>& graph, int cur, string& s, int& res) {
        int firstBig = 0, secondBig = 0;
        for (auto next : graph[cur]) {
            int ret = dfs(graph, next, s, res);
            if(s[cur] == s[next]) continue;
            if(ret > firstBig) {
                secondBig = firstBig;
                firstBig = ret;
            } else if(ret > secondBig) {
                secondBig = ret;
            }
        }
        res = max(res, firstBig + secondBig + 1);
        return firstBig + 1;
    }
};