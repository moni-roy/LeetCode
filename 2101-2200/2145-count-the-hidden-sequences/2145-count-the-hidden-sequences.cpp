class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        vector<long long> nums(n+1, 0);
        nums[0] = lower;
        for (int i = 1; i <= n; ++i) {
            nums[i] = nums[i-1] + differences[i-1];
        }
        long long mn = *min_element(nums.begin(), nums.end());
        long long mx = *max_element(nums.begin(), nums.end());
        int res = 0;
        if (mn <= lower) {
            mx += lower - mn;
        }
        else if(mn > lower) {
            mx -= mn - lower;
        }
        if (mx <= upper) {
            res += upper - mx + 1;
        }
        return res;
    }
};