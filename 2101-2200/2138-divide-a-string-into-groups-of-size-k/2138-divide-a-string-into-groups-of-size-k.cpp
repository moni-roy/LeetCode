class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string tmp;
        for (int i = 0; i < s.size(); ++i) {
            if (i % k == 0) {
                if (tmp.size()) {
                    ans.push_back(tmp);
                    tmp.clear();
                }
            }
            tmp.push_back(s[i]);
        }
        if(tmp.size() > 0 && tmp.size() < k) {
            tmp.append(k - tmp.size(), fill);
        }
        ans.push_back(tmp);
        return ans;
    }
};