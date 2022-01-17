class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(4001, 0));
        return dfs(0, nums, target, dp);
    }
private:
    int dfs(int p, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if(p==nums.size() ) {
            return (target == 0);
        }
        if(dp[p][target+2000] != 0) {
            return dp[p][target+2000];
        }
        int res = 0;
        res += dfs(p+1, nums, target-nums[p], dp);
        res += dfs(p+1, nums, target+nums[p], dp);
        dp[p][target+2000] = res;
        return res;
    }
};