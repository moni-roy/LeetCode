class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int max_val = *max_element(nums.begin(), nums.end());
        
        int low = 0, high = max_val;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (check(nums, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
private:
    bool check(vector<int> nums, int mid) {
        long long over = 0;
        for (int i = nums.size() - 1; i >= 1; --i) {
            if (nums[i] + over > mid) {
                over = over + nums[i] - mid;;
            } else {
                over = 0;
            }
        }
        return nums[0] + over <= mid;
    }
};