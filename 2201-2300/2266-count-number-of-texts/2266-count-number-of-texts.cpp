class Solution {
public:
    int countTexts(string s) {
        int n = s.size(), mod = 1e9 + 7;
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            dp[i] = dp[i-1];
            if(i-2 >= 0 && s[i-1] == s[i-2]) dp[i] += dp[i-2];
            if(i-3 >= 0 && s[i-1] == s[i-2] && s[i-1] == s[i-3]) dp[i] += dp[i-3];
            if(i-4 >= 0 && (s[i-1] == '7' || s[i-1] == '9') && s[i-1] == s[i-2] && s[i-1] == s[i-3] && s[i-1] == s[i-4]) dp[i] += dp[i-4];
            dp[i] %= mod;
        }
        return dp[n];
    }
};