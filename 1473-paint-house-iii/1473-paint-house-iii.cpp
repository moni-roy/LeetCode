class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(target + 1, vector<int>(n + 1, -1)));
        int ans = recur(houses, cost, dp, 0, 0, 0, target);
        return ans == INF ? -1 : ans;
    }
private:
    const int INF = 1000001;
    int recur(vector<int>& houses, vector<vector<int>>& cost, vector<vector<vector<int>>>& dp, int cur, int count, int prev, int target) {
        if (cur == houses.size()) {
            return count == target ? 0 : INF;
        }
        if (count > target) return INF;
        if (dp[cur][count][prev] != -1) {
            return dp[cur][count][prev];
        }
        int res = INF;
        if(houses[cur]) {
            res = recur(houses, cost, dp, cur + 1, count + (prev != houses[cur]) , houses[cur], target);
        } else {
            for (int i = 1; i <= cost[cur].size(); i++) {
                res = min(res, cost[cur][i - 1] + recur(houses, cost, dp, cur + 1, count + (prev != i), i, target));
            }
        }
        return dp[cur][count][prev] = res;
    }
};