
struct unionFind {
    vector<int> parent, rank, size;
    int root(int x) {
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }
    void init(int n) {
        parent.resize(n);
        rank.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }
    void merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (rank[x] > rank[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
            if (rank[x] == rank[y]) rank[y]++;
        }
    }
};

class Solution {
public:

    int largestComponentSize(vector<int>& nums) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            for (int j = 2; j * j <= x; j++) {
                if (x % j == 0) {
                    m[j].push_back(i);
                    m[x / j].push_back(i);
                }
            }
            m[x].push_back(i);
        }
        int n = nums.size();
        int ans = 0;
        unionFind uf;
        uf.init(n);
        for (auto p : m) {
            int x = p.first;
            vector<int>& v = p.second;

            for (int i = 0; i < v.size() -1; i++) {
                uf.merge(v[i], v[i + 1]);
            }

            ans = max(ans, uf.size[uf.root(v[0])]);
        }
        return ans;
    }
};