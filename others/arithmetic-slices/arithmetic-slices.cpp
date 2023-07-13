class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i+2;
            while (j < n && nums[j] - nums[j-1] == nums[j - 1] - nums[j - 2])
                j++;
            int t = (j - i - 2);
            ans += t * (t + 1) / 2;
            i = j - 2;
        }
        return ans;
    }
};