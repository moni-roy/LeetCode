class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s1(nums1.begin(), nums1.end());
        for (int i = 0; i < nums2.size(); ++i) {
            if (s1.count(nums2[i])) {
                res.push_back(nums2[i]);
                s1.erase(nums2[i]);
            }
        }
        return res;
    }
};