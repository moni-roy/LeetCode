class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        int ans = 0;
        
        int i = 0;
        while(i < n) {
            int idx = i + 2;
            
            while(idx < n && nums[idx] - nums[idx - 1] == nums[idx - 1] - nums[idx - 2]) {
                idx++;
            }
            int dif = idx - i - 2;
            ans += (dif * (dif + 1) / 2);
            i = idx - 1;
        }
        
        return ans;
    }
};