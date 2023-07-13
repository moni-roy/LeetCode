class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto n : nums) sum += n;
        if(sum & 1) return false;
        sum >>= 1;
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum + 1, false));
        vector<vector<bool>> vs(nums.size() + 1, vector<bool>(sum + 1, false));
        return dfs(nums, dp, 0, sum, vs);
    }
    bool dfs(vector<int>& nums, vector<vector<bool>>& dp, int i, int sum, vector<vector<bool>>& vs) {
        if(i == nums.size() || sum <= 0) return sum == 0;
        if(vs[i][sum]) return dp[i][sum];
        vs[i][sum] = true;
        bool res = false;
        res = dfs(nums, dp, i + 1, sum, vs) || dfs(nums, dp, i + 1, sum - nums[i], vs);
        return dp[i][sum] = res;
    }
};