class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int nOnes = 0;
        for (int i = 0; i < n; ++i) nOnes += nums[i];


        for (int i = 0; i < n; ++i) nums.push_back(nums[i]);
        int curr = 0, mx = 0;
        int i = 0, j = 0;
        while (j < nums.size()) {
            curr += nums[j];
            if(j - i + 1 == nOnes) {
                mx = max(curr, mx);
                if(nums[i] == 1) {
                    curr--;
                }
                ++i;
            }
            ++j;
        }
        return nOnes - mx;
    }
};
