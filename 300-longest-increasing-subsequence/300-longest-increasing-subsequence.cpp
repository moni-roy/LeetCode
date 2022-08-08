class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n);
        dp[0] = nums[0];
        int max_len = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > dp[max_len - 1]) {
                dp[max_len] = nums[i];
                max_len++;
            } else {
                int l = lower_bound(dp.begin(), dp.begin() + max_len, nums[i]) - dp.begin();
                dp[l] = nums[i];
            }
        }
        return max_len;
    }
};