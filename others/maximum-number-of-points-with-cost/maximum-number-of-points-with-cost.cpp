class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        long long ans = 0;
        vector<vector<long long> > dp(2, vector<long long>(points[0].size(), 0));
        for(int i = 0; i < points[0].size(); i++) {
            dp[0][i] = points[0][i];
        }
        int idx = 0;
        for(int i = 1; i < points.size(); i++) {
            vector<long long> left(points[0].size()), right(points[0].size());
            left[0] = dp[idx][0];
            for(int j = 1; j < points[i].size(); j++) {
                left[j] = max(dp[idx][j], left[j-1] - 1);
            }
            right[points[i-1].size()-1] = dp[idx][points[i].size()-1];
            for(int j = points[i].size()-2; j >= 0; j--) {
                right[j] = max(dp[idx][j], right[j+1] - 1);
            }
            idx = 1 - idx;
            for(int j = 0; j < points[i].size(); j++) {
                dp[idx][j] = max(dp[idx][j], left[j] + points[i][j]);
                dp[idx][j] = max(dp[idx][j], right[j] + points[i][j]);
            }
        }
        for (int i = 0; i < points[0].size(); i++) {
            ans = max(ans, dp[idx][i]);
        }
        return ans;
    }
};