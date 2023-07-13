class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        if (words.size() == 0) return res;
        res.push_back(words[0]);
        for (int i = 1; i < words.size(); i++) {
            string tmp = words[i];
            string last = res.back();
            sort(tmp.begin(), tmp.end());
            sort(last.begin(), last.end());
            if (tmp != last) res.push_back(words[i]);
        }
        return res;
    }
};