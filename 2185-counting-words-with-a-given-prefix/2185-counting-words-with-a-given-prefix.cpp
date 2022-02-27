class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() < pref.size()) {
                continue;
            }
            if (words[i].substr(0, pref.size()) != pref) {
                continue;
            }
            res++;
        }
        return res;
    }
};