class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) return true;
            if (nums[m] < nums[r]) {
                if (nums[m] < target && target <= nums[r]) l = m + 1;
                else r = m - 1;
            } else if (nums[m] > nums[r]) {
                if (nums[l] <= target && target < nums[m]) r = m - 1;
                else l = m + 1;
            } else r--;
        }
        return false;
    }
};