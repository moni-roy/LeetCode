class Solution {
public:
  int md = 1e9 + 7;
  int countVowelPermutation(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(6, -1));
    return dpFun(n, 0, dp);
  }
  int dpFun(int n, int c, vector<vector<int>>& dp) {
    if (n == 0) return 1;
    if (dp[n][c] != -1) return dp[n][c];
    int ret = 0;
    if (c == 0) {
      for (int i = 1; i <= 5; i++) {
        ret += dpFun(n - 1, i, dp);
        ret %= md;
      }
    }
    else if (c == 1) ret += dpFun(n - 1, 2, dp);
    else if (c == 2) ret += (dpFun(n - 1, 1, dp) + dpFun(n - 1, 3, dp)) % md;
    else if (c == 3) {
      for (int i = 1; i <= 5; i++) {
        if (i != 3) ret += dpFun(n - 1, i, dp);
        ret %= md;
      }
    }
    else if (c == 4)  ret += (dpFun(n - 1, 3, dp) + dpFun(n - 1, 5, dp)) % md;
    else ret = (ret + dpFun(n - 1, 1, dp)) % md;

    return dp[n][c] = ret % md;
  }
};