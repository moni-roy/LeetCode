class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        vector<bool> mp(202, false);
        int ans = 0;
  
        for (auto num : nums) {
            if (num >= 2 * diff) {
                ans += (mp[num - diff] and mp[num - 2 * diff]);
            }
            mp[num] = true;
        }
        return ans;
    }
};