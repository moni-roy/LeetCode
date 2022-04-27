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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        UnionFind uf(s.size());

        for(auto& p: pairs) {
            uf.unite(p[0], p[1]);
        }

        unordered_map<int, vector<int>> groups;
        unordered_map<int, vector<char>> group_chars;
        for(int i = 0; i < s.size(); i++) {
            int g = uf.find(i);
            groups[g].push_back(i);
            group_chars[g].push_back(s[i]);
        }
        string res(s.size(), 'a');
        for(auto& g: groups) {
            sort(group_chars[g.first].begin(), group_chars[g.first].end());
            for(int i = 0; i < g.second.size(); i++) {
                res[g.second[i]] = group_chars[g.first][i];
            }
        }
        return res;
    }
};