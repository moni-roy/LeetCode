class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        return slidingWindow(s, p);
    }
private:
    vector<int> slidingWindow(string s, string p) {
        vector<int> res;
        if (s.size() < p.size()) return res;
        unordered_map<char, int> pmap;
        unordered_map<char, int> smap;
        for (auto c : p) pmap[c]++;
        for (int i = 0; i < p.size(); i++) smap[s[i]]++;
        if(check(pmap, smap)) res.push_back(0);
        for (int i = p.size(); i < s.size(); i++) {
            smap[s[i]]++;
            smap[s[i - p.size()]]--;
            if (check(pmap, smap)) res.push_back(i - p.size() + 1);
        }
        return res;   
    }
    bool check(unordered_map<char, int>& pmap, unordered_map<char, int>& smap) {
        for (auto it : pmap) {
            if (it.second != smap[it.first]) return false;
        }
        return true;
    }
};