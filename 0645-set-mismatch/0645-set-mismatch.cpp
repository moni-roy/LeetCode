class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> mp;
        int dup = -1;
        for (auto n : nums) {
            mp[n] ++;
            if (mp[n] == 2) dup = n;
        }
        for (int i = 1; i <= nums.size(); i++) {
            if (mp.find(i) == mp.end()) return {dup, i};
        }
        return {};
    }
};