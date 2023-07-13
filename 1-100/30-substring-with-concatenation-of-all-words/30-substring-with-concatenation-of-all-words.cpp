class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int d = words[0].size();
        int sz = d * words.size();
        vector<int> ans;
        unordered_map<string, int> mp;
        for(auto w: words) mp[w] ++;
        
        for (int i = 0; i <= (n - sz); i++) {
            string t = s.substr(i, d);
            if (mp.find(t) != mp.end()) { 
                unordered_map<string, int> cp; 
                for (int j = i; j <= (i + sz - d); j += d) {
                    string tt = s.substr(j, d);
                    if(mp.find(tt) != mp.end()) cp[tt] ++;
                }
                if (cp == mp) ans.push_back(i);
            }
        }
        return ans;
    }
};