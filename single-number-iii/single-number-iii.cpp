class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long int x = 0;
        for (int i = 0; i < nums.size(); i++) {
            x ^= nums[i];
        }
        int mask = x & (-x);
        int a = 0, b = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & mask) {
                a ^= nums[i];
            } else {
                b ^= nums[i];
            }
        }
        return {a, b};
    }
};