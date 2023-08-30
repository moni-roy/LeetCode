class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        reverse(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];
            int y = nums[i - 1];
            if (x <= y)  continue;
            long long cnt = (y + x - 1LL) / y;
            ans += cnt - 1;
            nums[i] = nums[i] / cnt;
        }
        return ans;
    }
};