class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int> > graph;
        vector<int> indegree(n, 0);
        for (auto edge: relations) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            graph[u].push_back(v);
            indegree[v] ++;
        }
        // toplogical sort
        queue<int> q;
        vector<int> mTime(n, 0);
        for(int u = 0; u < n; u++) {
            if (indegree[u] == 0) {
                q.push(u);
                mTime[u] = time[u];
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v: graph[u]) {
                mTime[v] = max(mTime[u] + time[v], mTime[v]);
                indegree[v] --;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        int ret = 0;
        for (int u = 0; u < n; u++) {
            ret = max(ret, mTime[u]);
        }
        return ret;
    }
};