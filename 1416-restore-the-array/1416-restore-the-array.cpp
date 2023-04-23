class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<long long> dp(n + 1, -1);
        return dfs(s, k, 0, dp);
    }
private:
    int dfs(string& s, int k, int i, vector<long long>& dp) {
        if (i == s.size()) return 1;
        if (dp[i] != -1) return dp[i];
        if (s[i] == '0') return 0;
        long long num = 0;
        int res = 0;
        for (int j = i; j < s.size(); ++j) {
            num = num * 10 + s[j] - '0';
            if (num > k) break;
            res = (res + dfs(s, k, j + 1, dp)) % 1000000007;
        }
        return dp[i] = res;
    }
};