class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        for (int op = m - 1; op >= 0; op--) {
            for (int left = 0; left <= op; left++) {
                int right = n - op + left - 1;
                dp[op][left] = max(dp[op + 1][left + 1] + nums[left] * multipliers[op], dp[op + 1][left] + nums[right] * multipliers[op]);
            }
        }
        return dp[0][0];
    }
};