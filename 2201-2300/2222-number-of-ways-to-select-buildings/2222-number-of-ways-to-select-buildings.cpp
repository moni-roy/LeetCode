class Solution {
public:
    long long numberOfWays(string s) {
        vector<vector<long long>> dp(4, vector<long long>(2, 0));
        dp[0][1] = dp[0][0] = 1;
        
        for(int i = 0; i < s.size(); i++) {
            for(int l = 1; l <= 3; l++) {
                int t = s[i] - '0';
                dp[l][t] += dp[l - 1][1 - t];
            }
        }
        return dp[3][0] + dp[3][1];
    }
};