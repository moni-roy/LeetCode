class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res;
        unordered_map<int, bool> map_first;
        unordered_map<int, bool> map_second;
        for(auto i : nums1) map_first[i] = true;
        for(auto i : nums2) map_second[i] = true;
        vector<int> first_diff;
        vector<int> second_diff;
        for(auto num : map_first) {
            if(!map_second[num.first]) first_diff.push_back(num.first);
        }
        for(auto num : map_second) {
            if(!map_first[num.first]) second_diff.push_back(num.first);
        }
        res.push_back(first_diff);
        res.push_back(second_diff);
        return res;
    }
};