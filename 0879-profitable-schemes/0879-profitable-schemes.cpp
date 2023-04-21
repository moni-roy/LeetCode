class Solution
{
public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit) {
        int m = group.size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));
        return dfs(n, minProfit, group, profit, 0, 0, 0, dp);
    }

private:
    int dfs(int n, int minProfit, vector<int> &group, vector<int> &profit, int curProfit,
            int curGroup, int curIdx, vector<vector<vector<int>>> &dp) {
        if (curIdx == group.size()) {
            return curProfit >= minProfit ? 1 : 0;
        }
        if (dp[curIdx][curGroup][curProfit] != -1) {
            return dp[curIdx][curGroup][curProfit];
        }
        int res = dfs(n, minProfit, group, profit, curProfit, curGroup, curIdx + 1, dp);
        res %= 1000000007;
        if (curGroup + group[curIdx] <= n) {
            res += dfs(n, minProfit, group, profit, min(minProfit, curProfit + profit[curIdx]), curGroup + group[curIdx], curIdx + 1, dp);
            res %= 1000000007;
        }
        dp[curIdx][curGroup][curProfit] = res;
        return res;
    }
};