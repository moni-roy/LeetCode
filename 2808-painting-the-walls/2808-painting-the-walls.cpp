class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        vector<vector<int> > dp = vector(n, vector(n + 1, -1));
        return fun(0, n, cost, time, dp);
    }
private:
    int fun(int i, int remain, vector<int>& cost, vector<int>& time, vector<vector<int> > & dp) {
        if (remain <= 0) return 0;
        if (i == cost.size()) return 1e9;
        if (dp[i][remain] != -1) return dp[i][remain];
        int res = cost[i] + fun(i + 1, remain - 1 - time[i], cost, time, dp);
        res = min(res, fun(i + 1, remain, cost, time, dp));
        return dp[i][remain] = res;
    }
};