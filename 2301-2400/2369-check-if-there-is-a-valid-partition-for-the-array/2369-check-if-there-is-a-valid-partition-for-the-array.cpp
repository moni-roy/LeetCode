class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return rec(nums, dp, 0);
    }
private:
    bool rec(vector<int>& nums, vector<int>& dp, int i) {
        if (i == nums.size()) return true;
        if (dp[i] != -1) return dp[i];
        if (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
            if (rec(nums, dp, i + 2)) return dp[i] = true;
            if (i + 2 < nums.size() && nums[i] == nums[i + 2]) {
                if (rec(nums, dp, i + 3)) return dp[i] = true;
            }
        }
        if (i < nums.size() - 2 && nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2]) {
            if (rec(nums, dp, i + 3)) return dp[i] = true;
        }
        return dp[i] = false;
    }
};