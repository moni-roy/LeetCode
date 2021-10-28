class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int max_sum = nums[0];
        int min_sum = nums[0];
        int max_sum_non_circular = nums[0];
        int min_sum_non_circular = nums[0];
        int sum = nums[0];
        for (int i = 1; i < n; i++) {
            sum += nums[i];
            max_sum_non_circular = max(max_sum_non_circular + nums[i], nums[i]);
            min_sum_non_circular = min(min_sum_non_circular + nums[i], nums[i]);
            max_sum = max(max_sum, max_sum_non_circular);
            min_sum = min(min_sum, min_sum_non_circular);
        }
        return max_sum > 0 ? max(max_sum, sum - min_sum) : max_sum;
    }
};