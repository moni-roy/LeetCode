class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long m = 1, i = 0, ans = 0;
        while(m <= n) {
            if(i < nums.size() && nums[i] <= m) {
                m += nums[i++];
            }
            else {
                m += m;
                ans ++;
            }
        }
        return ans;
    }
};