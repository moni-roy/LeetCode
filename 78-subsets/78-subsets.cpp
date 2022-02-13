class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for(int mask = 0; mask < (1 << nums.size()); mask++) {
            vector<int> subset;
            for(int i = 0; i < nums.size(); i++) {
                if(mask & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            res.push_back(subset);
        }
        return res;
    }
};