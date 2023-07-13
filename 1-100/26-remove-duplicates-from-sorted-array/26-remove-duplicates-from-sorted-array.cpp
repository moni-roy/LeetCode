class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, bool> mp;
        int ans = 0;
        for(auto n: nums) {
            if(mp.find(n) == mp.end()) ans++;
            mp[n] = true;
        }
        int i = 0;
        for(auto it: mp) {
            nums[i++] = it.first;
        }
        return ans;
    }
};