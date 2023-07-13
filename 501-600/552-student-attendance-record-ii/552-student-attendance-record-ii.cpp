class Solution {
public:
    int checkRecord(int n) {
        long long mod = 1e9 + 7;
        vector<long long> dp(1000010, 0);
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 4;
        dp[3] = 7;
        for(int i = 4; i <= n; ++i) {
            dp[i] = ((dp[i-1]*2) % mod + (mod - dp[i-4])%mod) % mod;
        }
        long long sum = dp[n];
        for (int i = 1; i <= n; ++i) {
            sum += (dp[i-1] * dp[n-i]) % mod;
            sum%=mod;
        }
        return sum%mod;
    }
};