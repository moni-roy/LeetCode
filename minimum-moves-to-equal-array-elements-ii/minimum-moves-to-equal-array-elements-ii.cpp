class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1, ans = 0;
        while(l<r) {
            ans += nums[r--]-nums[l++];
        }
        return ans;
    }
};