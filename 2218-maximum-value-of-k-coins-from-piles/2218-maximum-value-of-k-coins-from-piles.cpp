class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        return maxValueOfCoins(n, k, piles, dp);
    }
private:
    int maxValueOfCoins(int n, int k, vector<vector<int>>& piles, vector<vector<int>>& dp) {
        if (n == 0) return 0;
        if (dp[n][k] != 0) return dp[n][k];
        int res = 0, curSum = 0;
        for (int cur = 0; cur <= min(k, (int) piles[n-1].size()); cur++) {
            if (cur > 0) curSum += piles[n - 1][cur - 1];
            res = max(res, curSum + maxValueOfCoins(n - 1, k - cur, piles, dp));
        }
        dp[n][k] = res;
        return res;
    }
};