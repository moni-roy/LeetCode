class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0], temp = 0;
        int n = nums.size();
        
        for (int i = 0; i < n-1; i++) {
            temp = nums[i];
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[j - 1]) {
                    temp += nums[j];
                }
                else break;
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};