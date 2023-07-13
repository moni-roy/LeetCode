class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int mn = INT_MAX;
        for (int i = 0; i < n; ++i) {
            mn = min(mn, nums[i]);
        }
        for (int i = 0; i < n; ++i) {
            ans += (nums[i] - mn);
        }
        return ans;
    }
};