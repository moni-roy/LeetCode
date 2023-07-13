class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for (int i = 0; i < nums1.size(); ++i) {
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            if (it == nums2.end()) {
                res.push_back(-1);
            } else {
                auto it2 = find_if(it + 1, nums2.end(), [nums1, i](int x) {
                    return nums1[i] < x;
                });
                if (it2 == nums2.end()) {
                    res.push_back(-1);
                } else {
                    res.push_back(*it2);
                }
            }
        }
        return res;
    }
};