class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);
        vector<bool> visited(n+1, false);
        return winnerSquareGameUsingDP(n, dp, visited);
    }
private:
    bool winnerSquareGameUsingDP(int n, vector<bool> &dp, vector<bool> &visited) {
        if(n == 1) return true;
        if(n == 2) return false;
        if(visited[n]) return dp[n];
        visited[n] = true;
        for(int i = 1; i*i <= n; i++) {
            dp[n] = dp[n] | !winnerSquareGameUsingDP(n - i*i, dp, visited);
        }
        return dp[n];
    }
};