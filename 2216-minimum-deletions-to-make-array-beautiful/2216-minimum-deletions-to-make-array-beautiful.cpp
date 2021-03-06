class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int prev = nums[0];
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[j] == prev) {
                j++;
                ans++;
            }
            i = j + 1;
            if (i < n) {
                prev = nums[i];
            }
            else break;
        }
        return (n - ans) & 1 ? ans + 1: ans;
    }
};