class Solution {
public:
    vector<int> dp = vector<int>(38, -1);
    int tribonacci(int n) {
        if(n == 0) return dp[0] = 0;
        if(n <= 2) return dp[n] = 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        
    }
};