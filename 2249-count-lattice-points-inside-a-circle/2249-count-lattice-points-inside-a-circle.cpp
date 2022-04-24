class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        unordered_set<int> s;
        for (auto &c : circles) {
            int r = c[2];
            int x = c[0];
            int y = c[1];
            for (int i = x - r; i <= x + r; i++) {
                for (int j = y - r; j <= y + r; j++) {
                    if (r * r >= (i - x) * (i - x) + (j - y) * (j - y)) {
                        s.insert(i * 100000 + j);
                    }
                }
            }
        }
        return s.size();
    }
};