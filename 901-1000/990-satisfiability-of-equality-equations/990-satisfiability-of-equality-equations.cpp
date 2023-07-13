class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26, 0);
        for (int i = 0; i < 26; ++i) {
            parent[i] = i;
        }
        for (auto& e : equations) {
            if (e[1] == '=') {
                int x = e[0] - 'a';
                int y = e[3] - 'a';
                int px = find(parent, x);
                int py = find(parent, y);
                if (px != py) {
                    parent[px] = py;
                }
            }
        }
        for (auto& e : equations) {
            if (e[1] == '!') {
                int x = e[0] - 'a';
                int y = e[3] - 'a';
                int px = find(parent, x);
                int py = find(parent, y);
                if (px == py) {
                    return false;
                }
            }
        }
        return true;
    }
private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
};