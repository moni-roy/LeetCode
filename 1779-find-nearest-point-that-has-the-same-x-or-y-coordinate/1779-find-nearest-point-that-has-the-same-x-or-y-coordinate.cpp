class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res = INT_MAX, idx = -1;
        for (int i = 0; i < points.size(); ++i) {
            auto p = points[i];
            if (x == p[0] || y == p[1]) {
                int d = abs(x - p[0]) + abs(y - p[1]);
                if (d < res) {
                    res = d;
                    idx = i;
                }
            }
        }
        return idx;
    }
};