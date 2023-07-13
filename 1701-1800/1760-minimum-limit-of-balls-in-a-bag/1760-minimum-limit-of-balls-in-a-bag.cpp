class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int m = (l + r) / 2;
            if (can(nums, m, maxOperations)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
private:
    bool can(vector<int>& nums, int m, int maxOperations) {
        int cnt = 0;
        for(int n : nums) {
            cnt += (n + m - 1) / m;
        }
        return nums.size() + maxOperations >= cnt;
    }
};