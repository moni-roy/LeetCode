class Solution {
public:
    int stoneGameVII(vector<int>& st) {
        int n = st.size();
        vector<vector<int> > dp(n, vector<int> (n, INT_MIN));
        int sum = accumulate(st.begin(), st.end(), 0);
        return dfs(0, n-1, dp, st, sum);
    }
    
    int dfs(int s, int e, vector<vector<int> > &dp, vector<int> &st, int sum) {
        if(s==e) return 0;
        if(dp[s][e]!= INT_MIN) return dp[s][e];
        dp[s][e] = max(sum - st[s] - dfs(s+1, e, dp, st, sum - st[s]), sum - st[e] - dfs(s, e-1, dp, st, sum - st[e]));
        return dp[s][e];
    }
};