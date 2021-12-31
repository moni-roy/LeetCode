class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(auto n: nums) {
            mp[n] ++;
        }
        for(auto it: mp) {
            if(k == 0) {
                if(it.second > 1) {
                    ans ++;
                }
            } else {
                if(mp.count(it.first + k)) {
                    ans ++;
                }
            }
        }
        return ans;
    }
};