class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1 && k&1) return -1;
        if(n == 1) return nums[0];
        int max_top = -1;
        for (int i = 0; i < n && i < k-1; i++) {
            max_top = max(max_top, nums[i]);
        }
        if(n > k) max_top = max(max_top, nums[k]);
        return max_top;
    }
};