class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int max_len = 1;
        int max_num = nums[0];

        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
                if (dp[i] > max_len) {
                    max_len = dp[i];
                    max_num = nums[i];
                }
            }
        }

        vector<int> ans;
        for (int i = n-1; i >= 0; --i) {
            if (dp[i] == max_len && max_num % nums[i] == 0) {
                ans.push_back(nums[i]);
                max_len--;
                max_num = nums[i];
            }
        }
        return ans;
    }
};