class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0);
        for(auto c: s) freq[c - 'a']++;
        for(auto c: t) freq[c - 'a']--;
        for(auto f: freq) {
            if(f != 0) return false;
        }
        return true;
    }
};