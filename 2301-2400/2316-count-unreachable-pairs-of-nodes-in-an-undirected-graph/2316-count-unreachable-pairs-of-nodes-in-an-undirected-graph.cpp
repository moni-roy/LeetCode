// union find with component size
// Time: O(n + m)
// Space: O(n + m)

class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    
    UnionFind(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) {
            return;
        }
        if (size[px] < size[py]) {
            swap(px, py);
        }
        parent[py] = px;
        size[px] += size[py];
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        // create graph
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // union find with component size
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j : graph[i]) {
                uf.merge(i, j);
            }
        }

        // get unique component size
        unordered_set<int> unique;
        for (int i = 0; i < n; ++i) {
            unique.insert(uf.find(i));
        }

        long long ans = 0, cnt = 0;
        for (auto i : unique) {
            cnt += uf.size[i];
            ans += uf.size[i] * (n - cnt);
        }
        return ans;
    }
};