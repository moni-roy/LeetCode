class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive, negative;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 0) {
                positive.push_back(nums[i]);
            } else {
                negative.push_back(nums[i]);
            }
        }
        int n = positive.size();
        vector<int> ans(nums.size());
        for (int i = 0; i < n; ++i) {
            ans[2 * i] = positive[i];
        }
        for (int i = 0; i < n; ++i) {
            ans[(i + 1) * 2 - 1] = negative[i];
        }
        return ans;
    }
};