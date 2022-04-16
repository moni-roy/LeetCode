class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = INT_MIN, mx = INT_MAX;
        for (auto num: nums) {
            if(abs(num - 0) == mx) {
                ans = max(ans, num);
            }
            else if(abs(num - 0) < mx) {
                mx = abs(num - 0);
                ans = num;
            }
        }
        return ans;
    }
};