class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (adj[i].size() == 1) leaves.push_back(i);
        }
        while (n > 2) {
            n -= leaves.size();
            vector<int> new_leaves;
            for (auto& l : leaves) {
                int v = adj[l].back();
                adj[v].erase(find(adj[v].begin(), adj[v].end(), l));
                if (adj[v].size() == 1) new_leaves.push_back(v);
            }
            leaves = new_leaves;
        }
        return leaves.size() != 0 ? leaves : vector<int>{0};
    }
};