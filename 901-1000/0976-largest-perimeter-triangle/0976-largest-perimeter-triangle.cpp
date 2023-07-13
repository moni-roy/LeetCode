class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {return a > b;});
        int i = 0;
        while (i < nums.size()) {
            if (i >= 2) {
                if (nums[i] + nums[i - 1] > nums[i - 2]) {
                    return nums[i] + nums[i - 1] + nums[i - 2];
                }
            }
            i++;
        }
        return 0;
    }
};