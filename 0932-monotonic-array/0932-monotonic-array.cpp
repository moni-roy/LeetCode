class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int isDes = 0, isAsc = 0;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= prev) isDes++;
            if (nums[i] >= prev) isAsc++;
            prev = nums[i];
        }
        return isDes == nums.size() - 1 || isAsc == nums.size() - 1;
    }
};