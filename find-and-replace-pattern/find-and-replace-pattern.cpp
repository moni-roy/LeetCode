class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        string normalize = normalizePattern(pattern);
        for(auto word: words) {
            if(normalizePattern(word) == normalize) ans.push_back(word);
        }
        return ans;
    }
    
    string normalizePattern(string s){
        unordered_map<char, int> mp;
        for(auto c: s) {
            if(!mp.count(c)) mp[c] = mp.size();
        }
        string r = "";
        for(int i = 0; i<s.size();i++){
            r += 'a' + mp[s[i]];
        }
        return r;
    }
};