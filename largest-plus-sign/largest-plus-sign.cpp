class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int> > grid(n, vector<int> (n, 1));
        for(auto m: mines) {
            grid[m[0]][m[1]] = 0;
        }
        vector<vector<int> > dp(n, vector<int> (n, 0));
        int ans = 0;
        
        for(int r = 0; r<n; r++) {
            int one = 0;
            for(int c = 0; c<n; c++) {
                one = grid[r][c]? one +1 : 0;
                dp[r][c] = one;
            }
            
            one = 0;
            for(int c = n-1; c >= 0; c--) {
                one = grid[r][c] ? one + 1 : 0;
                dp[r][c] = min(dp[r][c], one);
            }
        }
        for(int c = 0; c<n; c++) {
            int one = 0;
            for(int r = 0; r < n; r++) {
                one = grid[r][c] ? one + 1 : 0;
                dp[r][c] = min(dp[r][c], one);
            }
            one = 0;
            for(int r = n-1; r>=0; r--){
                one = grid[r][c] ? one + 1 : 0;
                dp[r][c] = min(dp[r][c], one);
                ans = max(ans, dp[r][c]);
            }
        }
        
        
        return ans;
    }
};