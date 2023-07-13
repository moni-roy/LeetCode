class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int> res;
        if (nums.size() == 0) return res;
        unordered_map<int, int> freq;
        for (auto& num : nums) {
            for (auto& n : num) {
                freq[n]++;
            }
        }
        for (auto& num : nums[0]) {
            if (freq[num] == nums.size()) {
                res.push_back(num);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};