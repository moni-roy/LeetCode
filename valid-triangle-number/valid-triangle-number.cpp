class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j<n && nums[i]!=0; j++) {
                int sm = nums[i] + nums[j];
                int k = lower_bound(nums.begin(), nums.end(), sm) - nums.begin();
                if(k>j) ans += k - j - 1;
            }
        }
        return ans;
    }
};