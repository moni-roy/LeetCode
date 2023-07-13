class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> dp(n, false);
        dp[0] = true;
        int pre = 0;
        for (int i = 1; i < n; ++i) {
            if( i >= minJump) pre += dp[i - minJump];
            if( i > maxJump) pre -= dp[i - maxJump - 1];
            dp[i] = pre > 0 & (s[i] == '0');
        }
        return dp[n - 1];
    }
};