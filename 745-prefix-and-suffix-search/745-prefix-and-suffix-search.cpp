class WordFilter {
public:
    unordered_map<string, int> mp;
    WordFilter(vector<string>& words) {
        for(int i = 0; i<words.size(); i++) {
            string w = words[i];
            for(int j = 1; j<=w.size(); j++) {
                for(int k = 0; k<w.size(); k++) {
                    string s = w.substr(0,j) + "#" +w.substr(k, w.size());
                    mp[s] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        string s = prefix + "#" + suffix;
        return mp.find(s) != mp.end() ? mp[s] : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */