#include <bits/stdc++.h>
using namespace std;

struct union_find {
    vector<int> p;
    vector<int> rank;
    vector<int> size;

    union_find(int n): p(n), rank(n), size(n) {
        iota(p.begin(), p.end(), 0);
        fill(rank.begin(), rank.end(), 0);
        fill(size.begin(), size.end(), 1);
    }

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) swap(x, y);
        p[y] = x;
        if (rank[x] == rank[y]) {
            rank[x]++;
            size[x] += size[y];
        } else {
            size[x] += size[y];
        }
    }
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        union_find uf (accounts.size());
        unordered_map<string, int> email_to_id;
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (email_to_id.find(accounts[i][j]) == email_to_id.end()) {
                    email_to_id[accounts[i][j]] = i;
                } else {
                    uf.unite(i, email_to_id[accounts[i][j]]);
                }
            }
        }
        unordered_map<int, vector<string>> id_to_email;
        for (auto& x: email_to_id) {
            id_to_email[uf.find(x.second)].push_back(x.first);
        }
        
        vector<vector<string>> res;
        for (auto& x: id_to_email) {
            vector<string> tmp;
            tmp.push_back(accounts[x.first][0]);
            tmp.insert(tmp.end(), x.second.begin(), x.second.end());
            sort(tmp.begin()+1, tmp.end());
            res.push_back(tmp);
        }
        return res;
        
    }
};