class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> g(n);
        vector<int> in(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            ++in[e[1]];
        }

        // every path count the number of each color
        vector<vector<int>> cnt(n, vector<int>(26));
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                q.push(i);
                cnt[i][colors[i] - 'a'] = 1;
            }
        }

        // check if there is a cycle and update the count of each color
        int ans = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                for (int i = 0; i < 26; ++i) {
                    cnt[v][i] = max(cnt[v][i], cnt[u][i] + (colors[v] - 'a' == i));
                }
                if (--in[v] == 0) {
                    q.push(v);
                }
            }
        }

        // check if there is a node with in-degree > 0
        for (int i = 0; i < n; ++i) {
            if (in[i] > 0) {
                return -1;
            }
            for (int j = 0; j < 26; ++j) {
                ans = max(ans, cnt[i][j]);
            }
        }
        return ans;
    }
};