class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int right = k;
        int left = k;
        int ans = nums[k];
        int curMin = ans;

        while (left > 0 || right < n - 1) {
            if ((left > 0 ? nums[left - 1]: 0) < (right < n - 1 ? nums[right + 1] : 0)) {
                right++;
                curMin = min(curMin, nums[right]);
            } else {
                left --;
                curMin = min(curMin, nums[left]);
            }
            ans = max(ans, curMin * (right - left + 1));
        }
        return ans;
    }
};