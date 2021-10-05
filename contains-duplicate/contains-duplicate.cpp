class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> mp;
        for(auto n: nums) {
            if(mp.find(n) != mp.end()) return true;
            mp[n] = 1;
        }
        return false;
    }
};