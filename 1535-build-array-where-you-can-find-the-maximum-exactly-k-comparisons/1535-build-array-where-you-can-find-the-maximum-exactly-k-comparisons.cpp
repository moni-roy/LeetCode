class Solution {
    const int md = 1e9 + 7;
public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int> > > dp(n, vector(m + 1, vector(k + 1, -1)));
        return fun(0, 0, n, m, k, dp);
    }
    int fun(int i, int mx, int n, int m, int k, vector<vector<vector<int> > > &dp) {
        if(i == n) return k == 0 ? 1 : 0;
        if (k < 0) return 0;
        if (dp[i][mx][k] != -1) return dp[i][mx][k];
        int ret = 0;
        for (int x = 1; x <= mx; x++) {
            ret = (ret + fun(i + 1, mx, n, m, k, dp)) % md;
        }
        for (int x = mx + 1; x <= m; x++) {
            ret = (ret + fun(i + 1, x, n, m, k - 1, dp)) % md;
        }
        return dp[i][mx][k] = ret;
    }
};