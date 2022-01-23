class Solution {
public:
    int countElements(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (auto num : nums) {
            bool hasSmaller = false, hasLarger = false;
            for (auto num2 : nums) {
                if (num2 < num) {
                    hasSmaller = true;
                }
                if (num2 > num) {
                    hasLarger = true;
                }
            }
            if (hasSmaller && hasLarger) {
                ans++;
            }
        }
        return ans;
    }
};