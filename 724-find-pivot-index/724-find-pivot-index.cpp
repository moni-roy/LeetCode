class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> left_sum(nums.size(), 0), right_sum(nums.size(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            left_sum[i] = sum;
        }
        sum = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            sum += nums[i];
            right_sum[i] = sum;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (left_sum[i] == right_sum[i]) {
                return i;
            }
        }
        return -1;
    }
};