class UnionFind {
    int n;
    vector<int> p, size;
public:
    UnionFind(int n) : n(n), p(n), size(n, 1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void connect(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        p[y] = x;
        size[x] += size[y];
        n--;
    }
    int getSize(int x) {
        return size[find(x)];
    }
    int getCount() {
        return n;
    }
};

class Solution {
public:
    vector<int> groupStrings(vector<string>& words) {
        int n = words.size();
        UnionFind uf(n);
        unordered_map<int, int> mapping;

        for (int i = 0; i < n; ++i) {
           int mask = 0;
           for (auto c: words[i]) {
               mask |= 1 << (c - 'a'); // current mask
           }
           // if(mapping.count(mask)) continue;
           for(int j = 0; j < 26; ++j) {
                if (mask & (1 << j)) {
                    int new_mask = mask ^ (1 << j); // delete one char
                    if (mapping.count(new_mask)) {
                        uf.connect(i, mapping[new_mask]);
                    }
                    for (int k = 0; k < 26; ++k) { // replace one character
                        if(new_mask & (1 << k)) {
                            continue;
                        }
                        int nMask = new_mask | (1 << k);
                        if (mapping.count(nMask)) {
                            uf.connect(i, mapping[nMask]);
                        }
                    }
                }
                else {
                    int new_mask = mask | (1 << j); // add one char
                    if (mapping.count(new_mask)) {
                        uf.connect(i, mapping[new_mask]);
                    }
                }
           }
           mapping[mask] = uf.find(i);
        }
        int maxSize = 0;
        for (int i = 0; i < n; ++i) {
            maxSize = max(maxSize, uf.getSize(i));
        }
        return {uf.getCount(), maxSize};

    }
};