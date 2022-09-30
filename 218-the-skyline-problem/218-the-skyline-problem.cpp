class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int, int>> height;
        for (auto b : buildings) {
            height.push_back({b[0], -b[2]});
            height.push_back({b[1], b[2]});
        }
        sort(height.begin(), height.end());
        multiset<int> m{0};
        int prev = 0;
        for (auto h : height) {
            if (h.second < 0) m.insert(-h.second);
            else m.erase(m.find(h.second));
            int cur = *m.rbegin();
            if (cur != prev) {
                res.push_back({h.first, cur});
                prev = cur;
            }
        }
        return res;
    }
};