class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size()+1, -1));
        return dfs(0,0,s, p, dp);
    }
    
    bool dfs(int x, int y, string &A, string &B, vector<vector<int> > &dp) {
        if(y == B.size()) return A.size() == x;
        if(dp[x][y]!=-1) return dp[x][y];
        if(x == A.size()) {
            int ret = (B[y]=='*') ? dfs(x, y+1, A, B, dp) : false;
            dp[x][y] = ret;
            return ret;
        }
        bool ret = false;
        if(B[y] == '?' || A[x] == B[y]) ret = dfs(x+1, y+1, A, B, dp);
        else if(B[y] == '*'){
            ret = dfs(x+1, y, A, B, dp) || dfs(x, y+1, A, B, dp) || dfs(x+1, y+1, A, B, dp);
        }
        dp[x][y] = ret;
        return ret;
    }
};