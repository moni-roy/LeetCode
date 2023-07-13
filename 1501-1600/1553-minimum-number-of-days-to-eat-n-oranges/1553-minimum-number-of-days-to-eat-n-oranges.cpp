class Solution {
public:
    unordered_map<int, int> mp;
    int minDays(int n) {
        if(n <= 1) return n;
        if(mp.find(n) != mp.end()) return mp[n];
        mp[n] = min(minDays(n/2) + n%2, n%3 + minDays(n/3)) + 1;
        return mp[n];
    }
};