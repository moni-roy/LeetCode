class Solution {
public:
    int numWays(int steps, int arrLen) {
        vector <vector<int> > dp = vector(steps, vector(steps + 1, -1));
        return fun(0, steps, arrLen, dp);
    }
private:
    const int mod = 1e9 + 7;
    int fun(int pos, int steps, int arrLen, vector<vector<int> > & dp) {
        if (steps == 0) return pos == 0;
        if (dp[pos][steps] != -1) return dp[pos][steps];
        int ret = fun(pos, steps - 1, arrLen, dp);
        if (pos > 0) ret = (ret + fun(pos - 1, steps - 1, arrLen, dp)) % mod;
        if (pos < arrLen - 1) ret = (ret + fun(pos + 1, steps - 1, arrLen, dp)) % mod;
        return dp[pos][steps] = ret;
    }
};