class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        vector<int> res;
        for (auto n : nums) {
            if (m[n] == 1 && m[n-1] == 0 && m[n+1] == 0) {
                res.push_back(n);
            }
        }
        return res;
    }
};