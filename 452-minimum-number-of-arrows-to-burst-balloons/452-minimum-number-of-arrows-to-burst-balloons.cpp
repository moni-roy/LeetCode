class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int ans = 1;
        int end = points[0][1];
        for(int i = 1; i < points.size(); i++) {
            auto &p = points[i];
            if(p[0] > end) {
                ans++;
                end = p[1];
            }
        }
        return ans;
    }
};