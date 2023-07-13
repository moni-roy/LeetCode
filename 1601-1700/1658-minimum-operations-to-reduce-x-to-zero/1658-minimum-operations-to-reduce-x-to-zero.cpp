class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < x) return -1;
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0;

        for (int right = 0; right < n; right++) {
            sum -= nums[right];
            while (sum < x && left <= right) {
                sum += nums[left++];
            }
            if (sum == x) {
                ans = min(ans, n - right - 1 + left);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};