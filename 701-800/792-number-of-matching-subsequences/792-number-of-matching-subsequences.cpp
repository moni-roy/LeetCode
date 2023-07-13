class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<string> start[27];
        for(auto w: words) {
            start[w[0]-'a' + 1].push_back(w.substr(1));
        }
        
        for(auto c: s) {
            auto t = start[c-'a' + 1];
            start[c-'a' + 1].clear();
            for(auto i: t) {
                if(i.size() == 0) {
                    start[0].push_back(i);
                }
                else {
                    start[i[0]-'a' + 1].push_back(i.substr(1));
                }
            }
        }
        return start[0].size();
    }
};