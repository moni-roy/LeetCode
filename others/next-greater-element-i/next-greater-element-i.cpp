class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        for(int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] = i;
        }
        vector<int> ret;
        for(auto x: nums1) {
            int i = mp[x];
            int f = 0;
            for(; i < nums2.size(); i++) if(nums2[i] > x) {
                ret.push_back(nums2[i]);
                f = 1;
                break;
            }
            if(!f) ret.push_back(-1);
        }
        return ret;
    }
};