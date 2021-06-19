class Solution {
public:
    int md = 1e9 + 7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp = vector<vector<int>>(1001, vector<int>(1001, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                if(j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    int val = (dp[i - 1][j] + md - ((j - i) >= 0 ? dp[i - 1][j - i] : 0)) % md;
                    dp[i][j] = (dp[i][j-1] + val)%md;
                }
            }
        }
        return ((dp[n][k] + md - (k > 0 ? dp[n][k - 1] : 0)) % md);
    }
};