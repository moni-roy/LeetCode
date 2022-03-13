class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(auto d: dig){
            dp[d[0]][d[1]] = 1;
        }
        int res = 0;
        for(auto a: artifacts){
            int leftUpx = a[0], leftUpy = a[1];
            int rightDownx = a[2], rightDowny = a[3];
            bool flag = true;
            for(int i = leftUpx; i <= rightDownx; i++){
                for(int j = leftUpy; j <= rightDowny; j++){
                    if(dp[i][j] != 1){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag){
                res++;
            }
        }
        return res;
    }
};