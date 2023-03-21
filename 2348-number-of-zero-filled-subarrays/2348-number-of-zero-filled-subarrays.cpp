class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long cnt = 0;
        for (auto x : nums) {
            if (x != 0) {
                ans += cnt * (cnt + 1) / 2;
                cnt = 0;
            } else {
                cnt++;
            }
        }
        if (cnt > 0) {
            ans += cnt * (cnt + 1) / 2;
        }
        return ans;
    }
};