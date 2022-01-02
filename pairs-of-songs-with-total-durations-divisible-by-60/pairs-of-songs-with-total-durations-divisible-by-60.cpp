class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(auto t: time) {
            t %= 60;
            if(t == 0) {if(mp.find(0) != mp.end()) ans += mp[0];}
            else if(mp.find(60 - t) != mp.end()) ans += mp[60-t];
            mp[t]++;
            
        }
        return ans;
    }
};