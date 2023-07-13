// union find
class UnionFind {
private:
    vector<int> parent;
    int count;
public:
    UnionFind(int n) {
        count = n;
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
            count--;
        }
    }
    
    int getCount() const {
        return count;
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        // union find
        int n = strs.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; j++) {
                if (isSimilar(strs[i], strs[j])) {
                    uf.unite(i, j);
                }
            }
        }
        return uf.getCount();
    }
private:
    bool isSimilar(string& a, string& b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) cnt++;
        }
        return cnt == 2 || cnt == 0;
    }
};