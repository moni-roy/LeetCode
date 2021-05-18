class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        for(auto path: paths) {
            stringstream ss(path);
            string word;
            vector<string> v;
            while (ss >> word) {
                v.push_back(word);
            }
            for(int i =1; i<v.size(); i++) {
                string s = v[i];
                int l = s.find('\(');
                string s1 = s.substr(0, l);
                string s2 = s.substr(l);
                mp[s2].push_back(v[0]+"/"+s1);
            }
        }
        vector<vector<string> > ret;
        for(auto m: mp) {
            if(m.second.size()>1) {
                ret.push_back(m.second);
            }
        }
        return ret;
    }
};