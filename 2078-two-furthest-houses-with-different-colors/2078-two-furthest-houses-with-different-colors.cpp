class Solution {
public:
    int maxDistance(vector<int>& colors) {
        return greedy(colors);
        int l = 0, r = colors.size()-1;
        vector<vector<int> > dp(r+1, vector<int>(r+1, -1));
        return dfs(colors, l, r, dp);
    }
private:
    int dfs(vector<int> &colors, int l, int r, vector<vector<int> >& dp) {
        if(l==r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        if(colors[l] != colors[r]) return r - l;
        return dp[l][r] = max(dfs(colors, l, r-1, dp), dfs(colors, l + 1, r, dp));
    }
    int greedy(vector<int> &colors) {
        int i = 0, j = colors.size() - 1, n = colors.size();
        while(colors[0] == colors[j]) j--;
        while(colors[i] == colors[n - 1]) i++;
        return max(j, n - i - 1);
    }
};