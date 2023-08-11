class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return fun(0, amount, coins, dp);
    }
private:
    int fun(int start, int rest, vector<int>& coins, vector<vector<int>> & dp) {
        if (rest == 0) return 1;
        if (start == coins.size()) return 0;
        if (dp[start][rest] != -1) return dp[start][rest];
        if (rest < coins[start]) return dp[start][rest] = fun(start + 1, rest, coins, dp);
        return dp[start][rest] = fun(start + 1, rest, coins, dp) + fun(start, rest - coins[start], coins, dp);
    }
};