class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) {
            return false;
        }
        int mp[33];
        for (int i = 0; i < 27; i++) {
            mp[i] = 0;
        }
        for (int i = 0; s[i]; i++) {
            mp[s[i] - 'a']++;
        }
        int cnt = 0;
        for (int i = 0; i < 27; i++) {
            cnt += (mp[i] & 1);
        }
        return cnt <= k;
    }
};