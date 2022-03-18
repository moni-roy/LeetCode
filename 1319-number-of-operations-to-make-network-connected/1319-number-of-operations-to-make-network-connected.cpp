class UnionFind {
private:
    vector<int> parent;
public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        parent[x] = y;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        UnionFind uf(n);
        int extra = 0;
        for (auto& c : connections) {
            if (uf.same(c[0], c[1])) {
                extra++;
            } else {
                uf.unite(c[0], c[1]);
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (uf.find(i) == i) count++;
        }
        if(count == 1) return 0;
        return count - 1 > extra ? -1 : min(count - 1, extra);
    }
};