class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = 0, mn = nums[0];
        for(auto num: nums) {
            mn = min(mn, num);
            ans = max(ans, num-mn);
        }
        return ans ? ans : -1;
    }
};